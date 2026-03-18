// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsample_ntt_tb__Syms.h"


VL_ATTR_COLD void Vsample_ntt_tb___024root__trace_init_sub__TOP__0(Vsample_ntt_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root__trace_init_sub__TOP__0\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("sample_ntt_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+177,0,"DWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+178,0,"KEEP_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+179,0,"Q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+177,0,"NUM_COEFFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+180,0,"NUM_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+174,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1,0,"t_data_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBit(c+9,0,"t_valid_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"t_last_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"t_keep_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+63,0,"t_ready_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+64,0,"t_data_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBit(c+66,0,"t_valid_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"t_last_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"t_keep_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+69,0,"t_ready_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"observed_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+71,0,"error_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+72,0,"done_seen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"bp_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+74,0,"cycle_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+177,0,"DWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+178,0,"KEEP_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+174,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1,0,"t_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBit(c+9,0,"t_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"t_last_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"t_keep_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+63,0,"t_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+64,0,"t_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBit(c+66,0,"t_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"t_last_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"t_keep_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+69,0,"t_ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+179,0,"Q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+177,0,"TARGET_COEFFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+181,0,"WFIFO_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+75,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("wfifo", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declArray(c+76+i*8,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 255,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+108,0,"wfifo_wr_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+109,0,"wfifo_rd_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+110,0,"wfifo_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declArray(c+111,0,"gbx_word0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+119,0,"gbx_word1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBit(c+127,0,"gbx_w0v",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"gbx_w1v",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+129,0,"gbx_boff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+130,0,"s1_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+131,0,"s1_d1_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+132,0,"s1_d2_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+133,0,"s1_d1_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+134,0,"s1_d2_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+135,0,"s1_d1_av",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"s1_d2_av",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"s1_d1_bv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"s1_d2_bv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("agg", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+139+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 11,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+143,0,"agg_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("oq", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declQuad(c+144,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 48,0);
    tracep->declQuad(c+146,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 48,0);
    tracep->popPrefix();
    tracep->pushPrefix("oq_valid", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+148+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBus(c+150,0,"coeff_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+151,0,"gbx_bit_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declQuad(c+152,0,"six_bytes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBit(c+154,0,"have_6bytes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+155,0,"b0_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+156,0,"b1_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+157,0,"b2_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+158,0,"b0_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+159,0,"b1_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+160,0,"b2_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+161,0,"d1_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+162,0,"d2_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+163,0,"d1_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+164,0,"d2_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+165,0,"s1_accepted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+166,0,"s1_will_emit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+167,0,"oq_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+168,0,"s1_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+169,0,"pipe_advance",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"state_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+170,0,"done_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"wfifo_wr_ptr_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+14,0,"wfifo_rd_ptr_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+15,0,"wfifo_count_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declArray(c+16,0,"gbx_word0_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declArray(c+24,0,"gbx_word1_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBit(c+32,0,"gbx_w0v_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"gbx_w1v_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"gbx_boff_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+35,0,"s1_valid_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"s1_d1_a_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+37,0,"s1_d2_a_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+38,0,"s1_d1_b_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+39,0,"s1_d2_b_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+40,0,"s1_d1_av_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"s1_d2_av_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"s1_d1_bv_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"s1_d2_bv_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("agg_nxt", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+44+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 11,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+48,0,"agg_count_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("oq_nxt", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declQuad(c+49,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 48,0);
    tracep->declQuad(c+51,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 48,0);
    tracep->popPrefix();
    tracep->pushPrefix("oq_valid_nxt", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+53+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBus(c+55,0,"coeff_count_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+56,0,"boff_plus6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+57,0,"cnt_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+58,0,"s0_d1_av",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"s0_d2_av",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"s0_d1_bv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"s0_d2_bv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+171,0,"lane",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+172,0,"got",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+173,0,"idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsample_ntt_tb___024root__trace_init_top(Vsample_ntt_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root__trace_init_top\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsample_ntt_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsample_ntt_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vsample_ntt_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsample_ntt_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsample_ntt_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsample_ntt_tb___024root__trace_register(Vsample_ntt_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root__trace_register\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vsample_ntt_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vsample_ntt_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vsample_ntt_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vsample_ntt_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsample_ntt_tb___024root__trace_const_0_sub_0(Vsample_ntt_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsample_ntt_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root__trace_const_0\n"); );
    // Init
    Vsample_ntt_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsample_ntt_tb___024root*>(voidSelf);
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsample_ntt_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsample_ntt_tb___024root__trace_const_0_sub_0(Vsample_ntt_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root__trace_const_0_sub_0\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+177,(0x100U),32);
    bufp->fullIData(oldp+178,(0x20U),32);
    bufp->fullIData(oldp+179,(0xd01U),32);
    bufp->fullIData(oldp+180,(0x400U),32);
    bufp->fullIData(oldp+181,(4U),32);
}

VL_ATTR_COLD void Vsample_ntt_tb___024root__trace_full_0_sub_0(Vsample_ntt_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsample_ntt_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root__trace_full_0\n"); );
    // Init
    Vsample_ntt_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsample_ntt_tb___024root*>(voidSelf);
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsample_ntt_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsample_ntt_tb___024root__trace_full_0_sub_0(Vsample_ntt_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root__trace_full_0_sub_0\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullWData(oldp+1,(vlSelfRef.sample_ntt_tb__DOT__t_data_i),256);
    bufp->fullBit(oldp+9,(vlSelfRef.sample_ntt_tb__DOT__t_valid_i));
    bufp->fullBit(oldp+10,(vlSelfRef.sample_ntt_tb__DOT__t_last_i));
    bufp->fullIData(oldp+11,(vlSelfRef.sample_ntt_tb__DOT__t_keep_i),32);
    bufp->fullCData(oldp+12,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state_nxt),2);
    bufp->fullCData(oldp+13,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr_nxt),2);
    bufp->fullCData(oldp+14,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr_nxt),2);
    bufp->fullCData(oldp+15,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt),3);
    bufp->fullWData(oldp+16,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt),256);
    bufp->fullWData(oldp+24,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt),256);
    bufp->fullBit(oldp+32,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v_nxt));
    bufp->fullBit(oldp+33,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v_nxt));
    bufp->fullCData(oldp+34,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff_nxt),5);
    bufp->fullBit(oldp+35,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid_nxt));
    bufp->fullSData(oldp+36,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_a_nxt),12);
    bufp->fullSData(oldp+37,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_a_nxt),12);
    bufp->fullSData(oldp+38,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_b_nxt),12);
    bufp->fullSData(oldp+39,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_b_nxt),12);
    bufp->fullBit(oldp+40,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_av_nxt));
    bufp->fullBit(oldp+41,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_av_nxt));
    bufp->fullBit(oldp+42,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_bv_nxt));
    bufp->fullBit(oldp+43,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_bv_nxt));
    bufp->fullSData(oldp+44,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[0]),12);
    bufp->fullSData(oldp+45,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[1]),12);
    bufp->fullSData(oldp+46,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[2]),12);
    bufp->fullSData(oldp+47,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[3]),12);
    bufp->fullCData(oldp+48,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt),3);
    bufp->fullQData(oldp+49,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                             [0U]),49);
    bufp->fullQData(oldp+51,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                             [1U]),49);
    bufp->fullBit(oldp+53,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[0]));
    bufp->fullBit(oldp+54,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[1]));
    bufp->fullSData(oldp+55,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt),9);
    bufp->fullCData(oldp+56,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__boff_plus6),6);
    bufp->fullSData(oldp+57,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__cnt_base),9);
    bufp->fullBit(oldp+58,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_av));
    bufp->fullBit(oldp+59,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d2_av));
    bufp->fullBit(oldp+60,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_bv));
    bufp->fullBit(oldp+61,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d2_bv));
    bufp->fullBit(oldp+62,(vlSelfRef.sample_ntt_tb__DOT__done));
    bufp->fullBit(oldp+63,(vlSelfRef.sample_ntt_tb__DOT__t_ready_o));
    bufp->fullQData(oldp+64,((0xffffffffffffULL & (
                                                   vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
                                                   [0U] 
                                                   >> 1U))),48);
    bufp->fullBit(oldp+66,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
                           [0U]));
    bufp->fullBit(oldp+67,(vlSelfRef.sample_ntt_tb__DOT__t_last_o));
    bufp->fullCData(oldp+68,((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
                              [0U] ? 0x3fU : 0U)),6);
    bufp->fullBit(oldp+69,(vlSelfRef.sample_ntt_tb__DOT__t_ready_i));
    bufp->fullIData(oldp+70,(vlSelfRef.sample_ntt_tb__DOT__observed_count),32);
    bufp->fullIData(oldp+71,(vlSelfRef.sample_ntt_tb__DOT__error_count),32);
    bufp->fullBit(oldp+72,(vlSelfRef.sample_ntt_tb__DOT__done_seen));
    bufp->fullCData(oldp+73,(vlSelfRef.sample_ntt_tb__DOT__bp_cnt),2);
    bufp->fullIData(oldp+74,(vlSelfRef.sample_ntt_tb__DOT__cycle_cnt),32);
    bufp->fullCData(oldp+75,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state),2);
    bufp->fullWData(oldp+76,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[0]),256);
    bufp->fullWData(oldp+84,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[1]),256);
    bufp->fullWData(oldp+92,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[2]),256);
    bufp->fullWData(oldp+100,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[3]),256);
    bufp->fullCData(oldp+108,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr),2);
    bufp->fullCData(oldp+109,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr),2);
    bufp->fullCData(oldp+110,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count),3);
    bufp->fullWData(oldp+111,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0),256);
    bufp->fullWData(oldp+119,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1),256);
    bufp->fullBit(oldp+127,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v));
    bufp->fullBit(oldp+128,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v));
    bufp->fullCData(oldp+129,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff),5);
    bufp->fullBit(oldp+130,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid));
    bufp->fullSData(oldp+131,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_a),12);
    bufp->fullSData(oldp+132,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_a),12);
    bufp->fullSData(oldp+133,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_b),12);
    bufp->fullSData(oldp+134,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_b),12);
    bufp->fullBit(oldp+135,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_av));
    bufp->fullBit(oldp+136,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_av));
    bufp->fullBit(oldp+137,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_bv));
    bufp->fullBit(oldp+138,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_bv));
    bufp->fullSData(oldp+139,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[0]),12);
    bufp->fullSData(oldp+140,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[1]),12);
    bufp->fullSData(oldp+141,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[2]),12);
    bufp->fullSData(oldp+142,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[3]),12);
    bufp->fullCData(oldp+143,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count),3);
    bufp->fullQData(oldp+144,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
                              [0U]),49);
    bufp->fullQData(oldp+146,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
                              [1U]),49);
    bufp->fullBit(oldp+148,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid[0]));
    bufp->fullBit(oldp+149,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid[1]));
    bufp->fullSData(oldp+150,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count),9);
    bufp->fullSData(oldp+151,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr),9);
    bufp->fullQData(oldp+152,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__six_bytes),48);
    bufp->fullBit(oldp+154,(((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v) 
                             & ((0x20U >= (0x3fU & 
                                           ((IData)(6U) 
                                            + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff)))) 
                                | (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v)))));
    bufp->fullCData(oldp+155,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b0_a),8);
    bufp->fullCData(oldp+156,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b1_a),8);
    bufp->fullCData(oldp+157,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b2_a),8);
    bufp->fullCData(oldp+158,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b0_b),8);
    bufp->fullCData(oldp+159,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b1_b),8);
    bufp->fullCData(oldp+160,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b2_b),8);
    bufp->fullSData(oldp+161,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d1_a),12);
    bufp->fullSData(oldp+162,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d2_a),12);
    bufp->fullSData(oldp+163,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d1_b),12);
    bufp->fullSData(oldp+164,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d2_b),12);
    bufp->fullCData(oldp+165,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_accepted),3);
    bufp->fullBit(oldp+166,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_will_emit));
    bufp->fullBit(oldp+167,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_full));
    bufp->fullBit(oldp+168,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_stall));
    bufp->fullBit(oldp+169,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__pipe_advance));
    bufp->fullBit(oldp+170,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__done_nxt));
    bufp->fullIData(oldp+171,(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__lane),32);
    bufp->fullIData(oldp+172,(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got),32);
    bufp->fullIData(oldp+173,(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx),32);
    bufp->fullBit(oldp+174,(vlSelfRef.sample_ntt_tb__DOT__clk));
    bufp->fullBit(oldp+175,(vlSelfRef.sample_ntt_tb__DOT__rst));
    bufp->fullBit(oldp+176,(vlSelfRef.sample_ntt_tb__DOT__start));
}
