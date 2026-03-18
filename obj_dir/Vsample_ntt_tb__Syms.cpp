// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsample_ntt_tb__pch.h"
#include "Vsample_ntt_tb.h"
#include "Vsample_ntt_tb___024root.h"

// FUNCTIONS
Vsample_ntt_tb__Syms::~Vsample_ntt_tb__Syms()
{
}

Vsample_ntt_tb__Syms::Vsample_ntt_tb__Syms(VerilatedContext* contextp, const char* namep, Vsample_ntt_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(471);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
