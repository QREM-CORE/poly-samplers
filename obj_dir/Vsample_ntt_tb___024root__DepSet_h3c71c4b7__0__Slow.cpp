// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsample_ntt_tb.h for the primary calling header

#include "Vsample_ntt_tb__pch.h"
#include "Vsample_ntt_tb___024root.h"

VL_ATTR_COLD void Vsample_ntt_tb___024root___eval_static(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_static\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__clk__0 
        = vlSelfRef.sample_ntt_tb__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__rst__0 
        = vlSelfRef.sample_ntt_tb__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__done_seen__0 
        = vlSelfRef.sample_ntt_tb__DOT__done_seen;
}

VL_ATTR_COLD void Vsample_ntt_tb___024root___eval_initial__TOP(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_initial__TOP\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.sample_ntt_tb__DOT__clk = 0U;
}

VL_ATTR_COLD void Vsample_ntt_tb___024root___eval_final(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_final\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsample_ntt_tb___024root___dump_triggers__stl(Vsample_ntt_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsample_ntt_tb___024root___eval_phase__stl(Vsample_ntt_tb___024root* vlSelf);

VL_ATTR_COLD void Vsample_ntt_tb___024root___eval_settle(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_settle\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vsample_ntt_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/sample_ntt_tb.sv", 20, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vsample_ntt_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsample_ntt_tb___024root___dump_triggers__stl(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___dump_triggers__stl\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsample_ntt_tb___024root___stl_sequent__TOP__0(Vsample_ntt_tb___024root* vlSelf);
VL_ATTR_COLD void Vsample_ntt_tb___024root____Vm_traceActivitySetAll(Vsample_ntt_tb___024root* vlSelf);

VL_ATTR_COLD void Vsample_ntt_tb___024root___eval_stl(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_stl\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vsample_ntt_tb___024root___stl_sequent__TOP__0(vlSelf);
        Vsample_ntt_tb___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vsample_ntt_tb___024root___stl_sequent__TOP__0(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___stl_sequent__TOP__0\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<16>/*511:0*/ __Vtemp_2;
    // Body
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__done_nxt = 0U;
    if ((0U != (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state))) {
        if ((1U != (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state))) {
            if ((2U == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state))) {
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__done_nxt = 1U;
            }
        }
    }
    vlSelfRef.sample_ntt_tb__DOT__t_last_o = (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
                                              [0U] 
                                              & (IData)(
                                                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
                                                        [0U]));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_accepted 
        = (7U & ((((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_av) 
                   + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_av)) 
                  + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_bv)) 
                 + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_bv)));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_will_emit 
        = ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid) 
           & (4U <= (0xfU & ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count) 
                             + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_accepted)))));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_full 
        = (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
           [0U] & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
           [1U]);
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_stall 
        = (((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_will_emit) 
            & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_full)) 
           & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__t_ready_i)));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__pipe_advance 
        = (1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_stall)));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr 
        = ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff) 
           << 3U);
    __Vtemp_2[0U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[0U];
    __Vtemp_2[1U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[1U];
    __Vtemp_2[2U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[2U];
    __Vtemp_2[3U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[3U];
    __Vtemp_2[4U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[4U];
    __Vtemp_2[5U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[5U];
    __Vtemp_2[6U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[6U];
    __Vtemp_2[7U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[7U];
    __Vtemp_2[8U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[0U];
    __Vtemp_2[9U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[1U];
    __Vtemp_2[0xaU] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[2U];
    __Vtemp_2[0xbU] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[3U];
    __Vtemp_2[0xcU] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[4U];
    __Vtemp_2[0xdU] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[5U];
    __Vtemp_2[0xeU] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[6U];
    __Vtemp_2[0xfU] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[7U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__six_bytes 
        = (0xffffffffffffULL & (((QData)((IData)(__Vtemp_2[
                                                 (((IData)(0x2fU) 
                                                   + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr)) 
                                                  >> 5U)])) 
                                 << ((0U == (0x1fU 
                                             & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr)))
                                      ? 0x20U : ((IData)(0x40U) 
                                                 - 
                                                 (0x1fU 
                                                  & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr))))) 
                                | (((0U == (0x1fU & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr)))
                                     ? 0ULL : ((QData)((IData)(
                                                               __Vtemp_2[
                                                               (((IData)(0x1fU) 
                                                                 + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr)) 
                                                                >> 5U)])) 
                                               << ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr))))) 
                                   | ((QData)((IData)(
                                                      __Vtemp_2[
                                                      ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr) 
                                                       >> 5U)])) 
                                      >> (0x1fU & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr))))));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b0_a = 
        (0xffU & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__six_bytes));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b1_a = 
        (0xffU & (IData)((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__six_bytes 
                          >> 8U)));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b2_a = 
        (0xffU & (IData)((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__six_bytes 
                          >> 0x10U)));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d1_a = 
        ((0xf00U & ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b1_a) 
                    << 8U)) | (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b0_a));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d2_a = 
        (((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b2_a) 
          << 4U) | (0xfU & ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b1_a) 
                            >> 4U)));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b0_b = 
        (0xffU & (IData)((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__six_bytes 
                          >> 0x18U)));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b1_b = 
        (0xffU & (IData)((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__six_bytes 
                          >> 0x20U)));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b2_b = 
        (0xffU & (IData)((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__six_bytes 
                          >> 0x28U)));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d1_b = 
        ((0xf00U & ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b1_b) 
                    << 8U)) | (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b0_b));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d2_b = 
        (((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b2_b) 
          << 4U) | (0xfU & ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__b1_b) 
                            >> 4U)));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[0U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[0U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[1U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[1U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[2U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[2U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[3U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[3U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[4U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[4U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[5U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[5U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[6U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[6U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[7U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[7U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[0U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[0U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[1U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[1U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[2U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[2U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[3U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[3U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[4U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[4U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[5U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[5U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[6U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[6U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[7U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[7U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_a_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_a;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_a_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_a;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_b_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_b;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_b_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_b;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_av_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_av;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_av_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_av;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_bv_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_bv;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_bv_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_bv;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[0U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg
        [0U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[1U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg
        [1U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[2U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg
        [2U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[3U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg
        [3U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[0U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
        [0U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[1U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
        [1U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[0U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
        [0U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[1U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
        [1U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__boff_plus6 = 0U;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__cnt_base = 0U;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_av = 0U;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d2_av = 0U;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_bv = 0U;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d2_bv = 0U;
    if ((0U == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state))) {
        if (vlSelfRef.sample_ntt_tb__DOT__start) {
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr_nxt = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state_nxt = 1U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr_nxt = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v_nxt = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v_nxt = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff_nxt = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid_nxt = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[0U] = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[0U] = 0ULL;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[0U] = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[1U] = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[1U] = 0ULL;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[1U] = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[2U] = 0U;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[3U] = 0U;
        }
    } else if ((1U == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state))) {
        if (((IData)(vlSelfRef.sample_ntt_tb__DOT__t_valid_i) 
             & (IData)(vlSelfRef.sample_ntt_tb__DOT__t_ready_o))) {
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr_nxt 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr_nxt)));
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt)));
        }
        if ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt
             [0U] & (IData)(vlSelfRef.sample_ntt_tb__DOT__t_ready_i))) {
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[0U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                [1U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[0U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt
                [1U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[1U] = 0U;
        }
        if (((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid) 
             & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__pipe_advance))) {
            if (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_av) {
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[(3U 
                                                                 & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt))] 
                    = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_a;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt)));
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)));
                if ((4U == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt))) {
                    if (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt
                        [0U]) {
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[1U] 
                            = ((1ULL & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [1U]) | (((QData)((IData)(
                                                          ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                            [3U] 
                                                            << 0xcU) 
                                                           | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                           [2U]))) 
                                          << 0x19U) 
                                         | ((QData)((IData)(
                                                            ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                              [1U] 
                                                              << 0xcU) 
                                                             | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                             [0U]))) 
                                            << 1U)));
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[1U] = 1U;
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[1U] 
                            = ((0x1fffffffffffeULL 
                                & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [1U]) | (IData)((IData)(
                                                        (0x100U 
                                                         == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)))));
                    } else {
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[0U] 
                            = ((1ULL & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [0U]) | (((QData)((IData)(
                                                          ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                            [3U] 
                                                            << 0xcU) 
                                                           | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                           [2U]))) 
                                          << 0x19U) 
                                         | ((QData)((IData)(
                                                            ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                              [1U] 
                                                              << 0xcU) 
                                                             | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                             [0U]))) 
                                            << 1U)));
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[0U] = 1U;
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[0U] 
                            = ((0x1fffffffffffeULL 
                                & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [0U]) | (IData)((IData)(
                                                        (0x100U 
                                                         == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)))));
                    }
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[0U] = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[1U] = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[2U] = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[3U] = 0U;
                }
            }
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid_nxt = 0U;
            if (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_av) {
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[(3U 
                                                                 & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt))] 
                    = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_a;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt)));
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)));
                if ((4U == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt))) {
                    if (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt
                        [0U]) {
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[1U] 
                            = ((1ULL & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [1U]) | (((QData)((IData)(
                                                          ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                            [3U] 
                                                            << 0xcU) 
                                                           | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                           [2U]))) 
                                          << 0x19U) 
                                         | ((QData)((IData)(
                                                            ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                              [1U] 
                                                              << 0xcU) 
                                                             | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                             [0U]))) 
                                            << 1U)));
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[1U] = 1U;
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[1U] 
                            = ((0x1fffffffffffeULL 
                                & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [1U]) | (IData)((IData)(
                                                        (0x100U 
                                                         == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)))));
                    } else {
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[0U] 
                            = ((1ULL & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [0U]) | (((QData)((IData)(
                                                          ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                            [3U] 
                                                            << 0xcU) 
                                                           | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                           [2U]))) 
                                          << 0x19U) 
                                         | ((QData)((IData)(
                                                            ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                              [1U] 
                                                              << 0xcU) 
                                                             | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                             [0U]))) 
                                            << 1U)));
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[0U] = 1U;
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[0U] 
                            = ((0x1fffffffffffeULL 
                                & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [0U]) | (IData)((IData)(
                                                        (0x100U 
                                                         == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)))));
                    }
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[0U] = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[1U] = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[2U] = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[3U] = 0U;
                }
            }
            if (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_bv) {
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[(3U 
                                                                 & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt))] 
                    = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_b;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt)));
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)));
                if ((4U == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt))) {
                    if (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt
                        [0U]) {
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[1U] 
                            = ((1ULL & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [1U]) | (((QData)((IData)(
                                                          ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                            [3U] 
                                                            << 0xcU) 
                                                           | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                           [2U]))) 
                                          << 0x19U) 
                                         | ((QData)((IData)(
                                                            ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                              [1U] 
                                                              << 0xcU) 
                                                             | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                             [0U]))) 
                                            << 1U)));
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[1U] = 1U;
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[1U] 
                            = ((0x1fffffffffffeULL 
                                & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [1U]) | (IData)((IData)(
                                                        (0x100U 
                                                         == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)))));
                    } else {
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[0U] 
                            = ((1ULL & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [0U]) | (((QData)((IData)(
                                                          ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                            [3U] 
                                                            << 0xcU) 
                                                           | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                           [2U]))) 
                                          << 0x19U) 
                                         | ((QData)((IData)(
                                                            ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                              [1U] 
                                                              << 0xcU) 
                                                             | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                             [0U]))) 
                                            << 1U)));
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[0U] = 1U;
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[0U] 
                            = ((0x1fffffffffffeULL 
                                & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [0U]) | (IData)((IData)(
                                                        (0x100U 
                                                         == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)))));
                    }
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[0U] = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[1U] = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[2U] = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[3U] = 0U;
                }
            }
            if (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_bv) {
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[(3U 
                                                                 & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt))] 
                    = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_b;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt)));
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)));
                if ((4U == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt))) {
                    if (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt
                        [0U]) {
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[1U] 
                            = ((1ULL & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [1U]) | (((QData)((IData)(
                                                          ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                            [3U] 
                                                            << 0xcU) 
                                                           | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                           [2U]))) 
                                          << 0x19U) 
                                         | ((QData)((IData)(
                                                            ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                              [1U] 
                                                              << 0xcU) 
                                                             | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                             [0U]))) 
                                            << 1U)));
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[1U] = 1U;
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[1U] 
                            = ((0x1fffffffffffeULL 
                                & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [1U]) | (IData)((IData)(
                                                        (0x100U 
                                                         == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)))));
                    } else {
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[0U] 
                            = ((1ULL & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [0U]) | (((QData)((IData)(
                                                          ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                            [3U] 
                                                            << 0xcU) 
                                                           | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                           [2U]))) 
                                          << 0x19U) 
                                         | ((QData)((IData)(
                                                            ((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                              [1U] 
                                                              << 0xcU) 
                                                             | vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
                                                             [0U]))) 
                                            << 1U)));
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[0U] = 1U;
                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt[0U] 
                            = ((0x1fffffffffffeULL 
                                & vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
                                [0U]) | (IData)((IData)(
                                                        (0x100U 
                                                         == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)))));
                    }
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[0U] = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[1U] = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[2U] = 0U;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt[3U] = 0U;
                }
            }
        }
        if (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__pipe_advance) {
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__cnt_base 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt;
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_av 
                = ((0xd01U > (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d1_a)) 
                   & (0x100U > (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__cnt_base)));
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d2_av 
                = ((0xd01U > (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d2_a)) 
                   & (0x100U > (0x1ffU & ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__cnt_base) 
                                          + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_av)))));
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_bv 
                = ((0xd01U > (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d1_b)) 
                   & (0x100U > (0x1ffU & (((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__cnt_base) 
                                           + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_av)) 
                                          + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d2_av)))));
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d2_bv 
                = ((0xd01U > (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d2_b)) 
                   & (0x100U > (0x1ffU & ((((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__cnt_base) 
                                            + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_av)) 
                                           + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d2_av)) 
                                          + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_bv)))));
            if ((((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v) 
                  & ((0x20U >= (0x3fU & ((IData)(6U) 
                                         + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff)))) 
                     | (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v))) 
                 & (0x100U > (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__cnt_base)))) {
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__boff_plus6 
                    = (0x3fU & ((IData)(6U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff)));
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid_nxt = 1U;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_a_nxt 
                    = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d1_a;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_av_nxt 
                    = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_av;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_a_nxt 
                    = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d2_a;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_av_nxt 
                    = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d2_av;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_b_nxt 
                    = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d1_b;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_bv_nxt 
                    = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d1_bv;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_b_nxt 
                    = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__d2_b;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_bv_nxt 
                    = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s0_d2_bv;
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff_nxt 
                    = (0x1fU & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__boff_plus6));
                if ((0x20U <= (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__boff_plus6))) {
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[0U] 
                        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[0U];
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[1U] 
                        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[1U];
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[2U] 
                        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[2U];
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[3U] 
                        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[3U];
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[4U] 
                        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[4U];
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[5U] 
                        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[5U];
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[6U] 
                        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[6U];
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[7U] 
                        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[7U];
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v_nxt 
                        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v_nxt;
                    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v_nxt = 0U;
                }
            } else {
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid_nxt = 0U;
            }
        }
        if (((~ (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v_nxt)) 
             & (0U < (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count)))) {
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr_nxt 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr_nxt)));
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt 
                = (7U & ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt) 
                         - (IData)(1U)));
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[0U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][0U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[1U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][1U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[2U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][2U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[3U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][3U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[4U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][4U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[5U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][5U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[6U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][6U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[7U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][7U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v_nxt = 1U;
        } else if ((((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v_nxt) 
                     & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v_nxt))) 
                    & (0U < (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count)))) {
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr_nxt 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr_nxt)));
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt 
                = (7U & ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt) 
                         - (IData)(1U)));
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[0U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][0U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[1U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][1U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[2U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][2U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[3U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][3U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[4U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][4U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[5U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][5U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[6U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][6U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[7U] 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo
                [vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr][7U];
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v_nxt = 1U;
        }
        if ((((((0x100U <= (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt)) 
                & (~ vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt
                   [0U])) & (~ vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt
                             [1U])) & (0U == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt))) 
             & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid_nxt)))) {
            vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state_nxt = 2U;
        }
    } else {
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state_nxt = 0U;
    }
}

VL_ATTR_COLD void Vsample_ntt_tb___024root___eval_triggers__stl(Vsample_ntt_tb___024root* vlSelf);

VL_ATTR_COLD bool Vsample_ntt_tb___024root___eval_phase__stl(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_phase__stl\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsample_ntt_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vsample_ntt_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsample_ntt_tb___024root___dump_triggers__act(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___dump_triggers__act\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge sample_ntt_tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge sample_ntt_tb.rst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge sample_ntt_tb.clk)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @( sample_ntt_tb.done_seen)\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsample_ntt_tb___024root___dump_triggers__nba(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___dump_triggers__nba\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge sample_ntt_tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge sample_ntt_tb.rst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge sample_ntt_tb.clk)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @( sample_ntt_tb.done_seen)\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsample_ntt_tb___024root____Vm_traceActivitySetAll(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root____Vm_traceActivitySetAll\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__Vm_traceActivity[7U] = 1U;
}

VL_ATTR_COLD void Vsample_ntt_tb___024root___ctor_var_reset(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___ctor_var_reset\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->sample_ntt_tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8727249763881749908ull);
    vlSelf->sample_ntt_tb__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9668872014491544263ull);
    vlSelf->sample_ntt_tb__DOT__start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3904633251565599310ull);
    vlSelf->sample_ntt_tb__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4596617908533515428ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->sample_ntt_tb__DOT__t_data_i, __VscopeHash, 11886959244764659205ull);
    vlSelf->sample_ntt_tb__DOT__t_valid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5500533050964283309ull);
    vlSelf->sample_ntt_tb__DOT__t_last_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10667624031946464477ull);
    vlSelf->sample_ntt_tb__DOT__t_keep_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4280024820608998750ull);
    vlSelf->sample_ntt_tb__DOT__t_ready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16277075622336461726ull);
    vlSelf->sample_ntt_tb__DOT__t_last_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 368518236455465203ull);
    vlSelf->sample_ntt_tb__DOT__t_ready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10212554453446635769ull);
    vlSelf->sample_ntt_tb__DOT__stimulus_bytes.atDefault() = 0;
    vlSelf->sample_ntt_tb__DOT__golden_coeffs.atDefault() = 0;
    vlSelf->sample_ntt_tb__DOT__observed_count = 0;
    vlSelf->sample_ntt_tb__DOT__error_count = 0;
    vlSelf->sample_ntt_tb__DOT__done_seen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9133381051912366358ull);
    vlSelf->sample_ntt_tb__DOT__bp_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12431062007124850752ull);
    vlSelf->sample_ntt_tb__DOT__cycle_cnt = 0;
    vlSelf->sample_ntt_tb__DOT__unnamedblk3__DOT__lane = 0;
    vlSelf->sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got = 0;
    vlSelf->sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx = 0;
    vlSelf->sample_ntt_tb__DOT__dut__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2759907949488282935ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(256, vlSelf->sample_ntt_tb__DOT__dut__DOT__wfifo[__Vi0], __VscopeHash, 15175594451653936916ull);
    }
    vlSelf->sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13051759212877171715ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 616547226836202865ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__wfifo_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6319348740578373812ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->sample_ntt_tb__DOT__dut__DOT__gbx_word0, __VscopeHash, 13710105707289521997ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->sample_ntt_tb__DOT__dut__DOT__gbx_word1, __VscopeHash, 12638775901423676264ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__gbx_w0v = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11991944237059868419ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__gbx_w1v = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6696886147727343658ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__gbx_boff = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8558360542813365255ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6808982996830055308ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d1_a = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 15797877045097366000ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d2_a = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 16779506801426047358ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d1_b = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 4214532886339431704ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d2_b = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 14647960531277568744ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d1_av = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6555776178444221321ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d2_av = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1056792556590703533ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d1_bv = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2679485997334733494ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d2_bv = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4578596369748196098ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sample_ntt_tb__DOT__dut__DOT__agg[__Vi0] = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 15231622217658133053ull);
    }
    vlSelf->sample_ntt_tb__DOT__dut__DOT__agg_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7781857559579787341ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->sample_ntt_tb__DOT__dut__DOT__oq[__Vi0] = VL_SCOPED_RAND_RESET_Q(49, __VscopeHash, 12514201492437606186ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->sample_ntt_tb__DOT__dut__DOT__oq_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8526640249259359812ull);
    }
    vlSelf->sample_ntt_tb__DOT__dut__DOT__coeff_count = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2903023657067677329ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 16076761237309470947ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__six_bytes = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 4842739758547790322ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__b0_a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3802971557524922269ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__b1_a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13392125853813691980ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__b2_a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15031614163910477001ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__b0_b = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18426241743125089397ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__b1_b = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3854990911181278395ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__b2_b = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16783977234867912914ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__d1_a = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 5869150438715799667ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__d2_a = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 12082917763617588950ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__d1_b = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 12886362547519550631ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__d2_b = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 8364684984074163257ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_accepted = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16905943274845434742ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_will_emit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9640474740588059530ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__oq_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16391900297642896050ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12351402447122156326ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__pipe_advance = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15951580403466298379ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__state_nxt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9876953112509109742ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__done_nxt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16317152704751627825ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr_nxt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11305648138685000592ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr_nxt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 201157800178573350ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7681143990569366669ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt, __VscopeHash, 14992688704638979826ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt, __VscopeHash, 16617612273260406259ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__gbx_w0v_nxt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10449729930589945263ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__gbx_w1v_nxt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16757416442686605781ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__gbx_boff_nxt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3343390907079493933ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_valid_nxt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15824244894655331152ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d1_a_nxt = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 9834359955730771456ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d2_a_nxt = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 5389290477136678709ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d1_b_nxt = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 4955774372025567959ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d2_b_nxt = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 4152187863586687424ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d1_av_nxt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2885400025537867637ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d2_av_nxt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14940469745592103607ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d1_bv_nxt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13371451669571948044ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s1_d2_bv_nxt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1431019078158123070ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sample_ntt_tb__DOT__dut__DOT__agg_nxt[__Vi0] = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 15651068721878685915ull);
    }
    vlSelf->sample_ntt_tb__DOT__dut__DOT__agg_count_nxt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8590772736984843266ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->sample_ntt_tb__DOT__dut__DOT__oq_nxt[__Vi0] = VL_SCOPED_RAND_RESET_Q(49, __VscopeHash, 16848299336141026575ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14014512003057061680ull);
    }
    vlSelf->sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 7907127247375550604ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__boff_plus6 = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 18169920866768284552ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__cnt_base = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 6287469146852772214ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s0_d1_av = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11754258578672347181ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s0_d2_av = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7964544592680940169ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s0_d1_bv = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4649843010562646133ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT__s0_d2_bv = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4425013856442435016ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT___Vpast_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17590950190164280799ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->sample_ntt_tb__DOT__dut__DOT___Vpast_1_0, __VscopeHash, 3533189268842285749ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT___Vpast_2_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3285342396453095121ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT___Vpast_3_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1195952211681749618ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT___Vpast_4_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16990064588648216165ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT___Vpast_5_0 = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 2954391069829971748ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT___Vpast_6_0 = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 5277990314442169175ull);
    vlSelf->sample_ntt_tb__DOT__dut__DOT___Vpast_7_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17890837394534556496ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13907715048198467610ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__wfifo_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 378801712218930864ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__coeff_count = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 13369425850509968326ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8127685275238359376ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0, __VscopeHash, 13871289726928616023ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i, __VscopeHash, 10483034511645602392ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_2_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13875922637380821854ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__t_keep_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10896338238853223311ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_3_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11043009916984388128ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__t_last_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15389665905729338536ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_4_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2185652774958962843ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_5_0 = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 3965539176429290055ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__oq[__Vi0] = VL_SCOPED_RAND_RESET_Q(49, __VscopeHash, 15897618922311710849ull);
    }
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_6_0 = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 17913068776335234776ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__oq_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1123513359052865155ull);
    }
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_7_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16340081082890712458ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__t_last_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3258809538428103342ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__t_valid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12456322347181817392ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__t_ready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2869622817713395070ull);
    vlSelf->__Vsampled_TOP__sample_ntt_tb__DOT__t_ready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3142576903699141622ull);
    vlSelf->__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14091070846939800001ull);
    vlSelf->__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__rst__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13242741496198699494ull);
    vlSelf->__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__done_seen__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12512225370329455068ull);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
