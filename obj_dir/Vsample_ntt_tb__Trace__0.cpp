// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsample_ntt_tb__Syms.h"


void Vsample_ntt_tb___024root__trace_chg_0_sub_0(Vsample_ntt_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsample_ntt_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root__trace_chg_0\n"); );
    // Init
    Vsample_ntt_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsample_ntt_tb___024root*>(voidSelf);
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsample_ntt_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsample_ntt_tb___024root__trace_chg_0_sub_0(Vsample_ntt_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root__trace_chg_0_sub_0\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((((vlSelfRef.__Vm_traceActivity
                        [1U] | vlSelfRef.__Vm_traceActivity
                        [2U]) | vlSelfRef.__Vm_traceActivity
                       [3U]) | vlSelfRef.__Vm_traceActivity
                      [4U])))) {
        bufp->chgWData(oldp+0,(vlSelfRef.sample_ntt_tb__DOT__t_data_i),256);
        bufp->chgBit(oldp+8,(vlSelfRef.sample_ntt_tb__DOT__t_valid_i));
        bufp->chgBit(oldp+9,(vlSelfRef.sample_ntt_tb__DOT__t_last_i));
        bufp->chgIData(oldp+10,(vlSelfRef.sample_ntt_tb__DOT__t_keep_i),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity
                      [7U])))) {
        bufp->chgCData(oldp+11,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state_nxt),2);
        bufp->chgCData(oldp+12,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr_nxt),2);
        bufp->chgCData(oldp+13,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr_nxt),2);
        bufp->chgCData(oldp+14,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt),3);
        bufp->chgWData(oldp+15,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt),256);
        bufp->chgWData(oldp+23,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt),256);
        bufp->chgBit(oldp+31,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v_nxt));
        bufp->chgBit(oldp+32,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v_nxt));
        bufp->chgCData(oldp+33,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff_nxt),5);
        bufp->chgBit(oldp+34,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid_nxt));
        bufp->chgSData(oldp+35,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_a_nxt),12);
        bufp->chgSData(oldp+36,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_a_nxt),12);
        bufp->chgSData(oldp+37,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_b_nxt),12);
        bufp->chgSData(oldp+38,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_b_nxt),12);
        bufp->chgBit(oldp+39,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_av_nxt));
        bufp->chgBit(oldp+40,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_av_nxt));
        bufp->chgBit(oldp+41,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_bv_nxt));
        bufp->chgBit(oldp+42,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_bv_nxt));
        bufp->chgSData(oldp+43,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[0]),12);
        bufp->chgSData(oldp+44,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[1]),12);
        bufp->chgSData(oldp+45,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[2]),12);
        bufp->chgSData(oldp+46,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[3]),12);
        bufp->chgCData(oldp+47,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt),3);
        bufp->chgQData(oldp+48,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [0U]),49);
        bufp->chgQData(oldp+50,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [1U]),49);
        bufp->chgBit(oldp+52,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[0]));
        bufp->chgBit(oldp+53,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[1]));
        bufp->chgSData(oldp+54,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt),9);
        bufp->chgCData(oldp+55,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__boff_plus6),6);
        bufp->chgSData(oldp+56,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__cnt_base),9);
        bufp->chgBit(oldp+57,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_av));
        bufp->chgBit(oldp+58,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d2_av));
        bufp->chgBit(oldp+59,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_bv));
        bufp->chgBit(oldp+60,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d2_bv));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+61,(vlSelfRef.sample_ntt_tb__DOT__done));
        bufp->chgBit(oldp+62,(vlSelfRef.sample_ntt_tb__DOT__t_ready_o));
        bufp->chgQData(oldp+63,((0xffffffffffffULL 
                                 & (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
                                    [0U] >> 1U))),48);
        bufp->chgBit(oldp+65,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
                              [0U]));
        bufp->chgBit(oldp+66,(vlSelfRef.sample_ntt_tb__DOT__t_last_o));
        bufp->chgCData(oldp+67,((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
                                 [0U] ? 0x3fU : 0U)),6);
        bufp->chgBit(oldp+68,(vlSelfRef.sample_ntt_tb__DOT__t_ready_i));
        bufp->chgIData(oldp+69,(vlSelfRef.sample_ntt_tb__DOT__observed_count),32);
        bufp->chgIData(oldp+70,(vlSelfRef.sample_ntt_tb__DOT__error_count),32);
        bufp->chgBit(oldp+71,(vlSelfRef.sample_ntt_tb__DOT__done_seen));
        bufp->chgCData(oldp+72,(vlSelfRef.sample_ntt_tb__DOT__bp_cnt),2);
        bufp->chgIData(oldp+73,(vlSelfRef.sample_ntt_tb__DOT__cycle_cnt),32);
        bufp->chgCData(oldp+74,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state),2);
        bufp->chgWData(oldp+75,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[0]),256);
        bufp->chgWData(oldp+83,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[1]),256);
        bufp->chgWData(oldp+91,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[2]),256);
        bufp->chgWData(oldp+99,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[3]),256);
        bufp->chgCData(oldp+107,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr),2);
        bufp->chgCData(oldp+108,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr),2);
        bufp->chgCData(oldp+109,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count),3);
        bufp->chgWData(oldp+110,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0),256);
        bufp->chgWData(oldp+118,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1),256);
        bufp->chgBit(oldp+126,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v));
        bufp->chgBit(oldp+127,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v));
        bufp->chgCData(oldp+128,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff),5);
        bufp->chgBit(oldp+129,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid));
        bufp->chgSData(oldp+130,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_a),12);
        bufp->chgSData(oldp+131,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_a),12);
        bufp->chgSData(oldp+132,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_b),12);
        bufp->chgSData(oldp+133,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_b),12);
        bufp->chgBit(oldp+134,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_av));
        bufp->chgBit(oldp+135,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_av));
        bufp->chgBit(oldp+136,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_bv));
        bufp->chgBit(oldp+137,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_bv));
        bufp->chgSData(oldp+138,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[0]),12);
        bufp->chgSData(oldp+139,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[1]),12);
        bufp->chgSData(oldp+140,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[2]),12);
        bufp->chgSData(oldp+141,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[3]),12);
        bufp->chgCData(oldp+142,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count),3);
        bufp->chgQData(oldp+143,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
                                 [0U]),49);
        bufp->chgQData(oldp+145,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
                                 [1U]),49);
        bufp->chgBit(oldp+147,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid[0]));
        bufp->chgBit(oldp+148,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid[1]));
        bufp->chgSData(oldp+149,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count),9);
        bufp->chgSData(oldp+150,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr),9);
        bufp->chgQData(oldp+151,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__six_bytes),48);
        bufp->chgBit(oldp+153,(((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v) 
                                & ((0x20U >= (0x3fU 
                                              & ((IData)(6U) 
                                                 + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff)))) 
                                   | (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v)))));
        bufp->chgCData(oldp+154,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b0_a),8);
        bufp->chgCData(oldp+155,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b1_a),8);
        bufp->chgCData(oldp+156,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b2_a),8);
        bufp->chgCData(oldp+157,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b0_b),8);
        bufp->chgCData(oldp+158,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b1_b),8);
        bufp->chgCData(oldp+159,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b2_b),8);
        bufp->chgSData(oldp+160,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d1_a),12);
        bufp->chgSData(oldp+161,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d2_a),12);
        bufp->chgSData(oldp+162,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d1_b),12);
        bufp->chgSData(oldp+163,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d2_b),12);
        bufp->chgCData(oldp+164,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_accepted),3);
        bufp->chgBit(oldp+165,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_will_emit));
        bufp->chgBit(oldp+166,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_full));
        bufp->chgBit(oldp+167,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_stall));
        bufp->chgBit(oldp+168,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__pipe_advance));
        bufp->chgBit(oldp+169,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__done_nxt));
        bufp->chgIData(oldp+170,(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__lane),32);
        bufp->chgIData(oldp+171,(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got),32);
        bufp->chgIData(oldp+172,(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx),32);
    }
    bufp->chgBit(oldp+173,(vlSelfRef.sample_ntt_tb__DOT__clk));
    bufp->chgBit(oldp+174,(vlSelfRef.sample_ntt_tb__DOT__rst));
    bufp->chgBit(oldp+175,(vlSelfRef.sample_ntt_tb__DOT__start));
}

void Vsample_ntt_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root__trace_cleanup\n"); );
    // Init
    Vsample_ntt_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsample_ntt_tb___024root*>(voidSelf);
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
}
