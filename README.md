# Poly-Samplers: High-Performance ML-KEM Polynomial Samplers

[![Standard: FIPS 203](https://img.shields.io/badge/Standard-FIPS%20203-red.svg)](https://csrc.nist.gov/pubs/fips/203/ipd)
[![Language: SystemVerilog](https://img.shields.io/badge/Language-SystemVerilog-blue.svg)](https://ieeexplore.ieee.org/document/8299595)
[![Target: FPGA / ASIC](https://img.shields.io/badge/Target-FPGA%20%2F%20ASIC-lightgrey.svg)]()
[![Verified with: Verilator](https://img.shields.io/badge/Verified%20with-Verilator-orange.svg)](https://www.veripool.org/verilator/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A high-performance SystemVerilog implementation of polynomial samplers for lattice-based cryptography, specifically targeting the **FIPS 203 ML-KEM (Kyber)** standard. This repository provides efficient, pipelined hardware modules for **SampleNTT** and **SamplePolyCBD**.

## Features

- **FIPS 203 Compliant**: Implements Algorithm 7 (SampleNTT) and Algorithm 8 (SamplePolyCBD) precisely as specified.
- **High Throughput**:
  - `sample_ntt`: Processes two byte-triples in parallel per cycle.
  - `sample_poly_cbd`: Processes 16/24 bits per cycle, emitting 4 coefficients per beat.
- **AXI4-Stream Interfaces**: Standard-compliant sink and source ports for seamless integration with Keccak/SHAKE cores and downstream NTT/PWM units.
- **Resource Optimized**:
  - Uses a **256-bit wide FIFO** architecture to enable BRAM inference and avoid massive LUT crossbars.
  - Transparent gearbox logic for cross-word boundary handling.
- **Pipelined Architecture**: Carefully balanced pipeline stages to ensure high clock frequency ($F_{max}$).
- **Dual-Simulator Support**: Verified with both **Verilator 5.0+** and **ModelSim/Questa**.

## Architecture Overview

The samplers share a common high-performance micro-architecture:

1.  **Wide FIFO**: Absorbs 256-bit AXI beats from the SHAKE core into a single-port BRAM-friendly buffer.
2.  **Gearbox**: A double-buffer system that extracts variable-length chunks (3-6 bytes) from the 256-bit stream without stalling.
3.  **Processing Core**:
    - `sample_ntt`: Dual-triple rejection sampling logic with pipelined comparators.
    - `sample_poly_cbd`: Unified popcount logic supporting both $\eta=2$ and $\eta=3$ security parameters.
4.  **Skid Buffer**: A 2-entry output queue to handle downstream back-pressure (AXI4-Stream handshake).

## Directory Structure

```text
.
├── rtl/
│   ├── sample_ntt.sv       # Rejection sampler for NTT coefficients
│   └── sample_poly_cbd.sv   # Centered Binomial Distribution sampler
├── tb/
│   ├── sample_ntt_tb.sv    # Self-checking testbench for SampleNTT
│   └── sample_poly_cbd_tb.sv # Unified testbench for SamplePolyCBD (η=2/3)
├── Makefile                # Dual-simulator build system
├── rtl.f                   # RTL file list
└── env.sh                  # Environment setup script
```

## Getting Started

### Prerequisites

- **Verilator** (v5.0 or later for `--timing` support) OR **ModelSim / Questa**.
- **GNU Make**.

### Simulation

To run all testbenches using Verilator:

```bash
make run_all SIM=verilator
```

To run a specific testbench (e.g., SamplePolyCBD):

```bash
make run_sample_poly_cbd_tb SIM=verilator
```

To use ModelSim (default):

```bash
make run_all
```

## Module Specifications

### `sample_ntt`
- **Input**: SHAKE-128 byte stream (via AXI4-Stream).
- **Output**: 256 coefficients in $\mathbb{Z}_q$ ($q=3329$).
- **Interface**: 4 × 12-bit packed coefficients per 48-bit output beat.

### `sample_poly_cbd`
- **Input**: Fixed-length byte stream (128 or 192 bytes).
- **Runtime Configuration**: `is_eta3` signal selects between $\eta=2$ (ML-KEM-512) and $\eta=3$ (ML-KEM-768/1024).
- **Output**: 256 coefficients in $\mathbb{Z}_q$.

## Performance & Optimization

The implementation addresses two critical bottlenecks in hardware sampling:
1.  **Multi-port RAM Bottleneck**: By using a 256-bit wide FIFO and a shift-MUX gearbox, we eliminate the need for byte-addressable multi-port RAMs, allowing tools to infer efficient block RAMs.
2.  **Timing Closure**: High-fanout combinational paths (especially the rejection sampling comparators) are broken into multiple cycles using pipeline registers, ensuring compatibility with modern FPGA/ASIC synthesis targets.

## Authors

- **Salwan Aldhahab**
- **Kiet Le**

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
