// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsample_ntt_tb.h for the primary calling header

#include "Vsample_ntt_tb__pch.h"
#include "Vsample_ntt_tb___024root.h"

VL_ATTR_COLD void Vsample_ntt_tb___024root___eval_initial__TOP(Vsample_ntt_tb___024root* vlSelf);
VlCoroutine Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__0(Vsample_ntt_tb___024root* vlSelf, VlProcessRef vlProcess);
VlCoroutine Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__1(Vsample_ntt_tb___024root* vlSelf);

void Vsample_ntt_tb___024root___eval_initial(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_initial\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsample_ntt_tb___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf, std::make_shared<VlProcess>());
    Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

extern const VlWide<8>/*255:0*/ Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0;

VL_INLINE_OPT VlCoroutine Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__0(Vsample_ntt_tb___024root* vlSelf, VlProcessRef vlProcess, VlForkSync __Vfork_1__sync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__0\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__unnamedblk2__DOT__lane;
    __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__unnamedblk2__DOT__lane = 0;
    IData/*31:0*/ __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__byte_idx;
    __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__byte_idx = 0;
    IData/*31:0*/ __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__beat_size;
    __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__beat_size = 0;
    // Body
    __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__unnamedblk2__DOT__lane = 0;
    __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__byte_idx = 0;
    __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__byte_idx = 0U;
    __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__beat_size = 0;
    {
        while ((VL_LTS_III(32, __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__byte_idx, vlSelfRef.sample_ntt_tb__DOT__stimulus_bytes.size()) 
                & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__done_seen)))) {
            __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__beat_size 
                = (vlSelfRef.sample_ntt_tb__DOT__stimulus_bytes.size() 
                   - __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__byte_idx);
            if (VL_LTS_III(32, 0x20U, __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__beat_size)) {
                __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__beat_size = 0x20U;
            }
            co_await vlSelfRef.__VtrigSched_h7e082ce5__0.trigger(0U, 
                                                                 vlProcess, 
                                                                 "@(negedge sample_ntt_tb.clk)", 
                                                                 "tb/sample_ntt_tb.sv", 
                                                                 160);
            vlSelfRef.__Vm_traceActivity[4U] = 1U;
            vlSelfRef.sample_ntt_tb__DOT__t_data_i[0U] 
                = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[0U];
            vlSelfRef.sample_ntt_tb__DOT__t_data_i[1U] 
                = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[1U];
            vlSelfRef.sample_ntt_tb__DOT__t_data_i[2U] 
                = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[2U];
            vlSelfRef.sample_ntt_tb__DOT__t_data_i[3U] 
                = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[3U];
            vlSelfRef.sample_ntt_tb__DOT__t_data_i[4U] 
                = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[4U];
            vlSelfRef.sample_ntt_tb__DOT__t_data_i[5U] 
                = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[5U];
            vlSelfRef.sample_ntt_tb__DOT__t_data_i[6U] 
                = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[6U];
            vlSelfRef.sample_ntt_tb__DOT__t_data_i[7U] 
                = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[7U];
            vlSelfRef.sample_ntt_tb__DOT__t_keep_i = 0U;
            __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__unnamedblk2__DOT__lane = 0U;
            while (VL_LTS_III(32, __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__unnamedblk2__DOT__lane, __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__beat_size)) {
                VL_ASSIGNSEL_WI(256,8,(0xffU & VL_MULS_III(32, (IData)(8U), __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__unnamedblk2__DOT__lane)), vlSelfRef.sample_ntt_tb__DOT__t_data_i, vlSelfRef.sample_ntt_tb__DOT__stimulus_bytes.at(
                                                                                (__Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__byte_idx 
                                                                                + __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__unnamedblk2__DOT__lane)));
                vlSelfRef.sample_ntt_tb__DOT__t_keep_i 
                    = (vlSelfRef.sample_ntt_tb__DOT__t_keep_i 
                       | (0xffffffffULL & ((IData)(1U) 
                                           << (0x1fU 
                                               & __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__unnamedblk2__DOT__lane))));
                __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__unnamedblk2__DOT__lane 
                    = ((IData)(1U) + __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__unnamedblk2__DOT__lane);
            }
            vlSelfRef.sample_ntt_tb__DOT__t_last_i 
                = VL_GTES_III(32, (__Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__byte_idx 
                                   + __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__beat_size), vlSelfRef.sample_ntt_tb__DOT__stimulus_bytes.size());
            vlSelfRef.sample_ntt_tb__DOT__t_valid_i = 1U;
            co_await vlSelfRef.__VtrigSched_h7e082d28__0.trigger(0U, 
                                                                 vlProcess, 
                                                                 "@(posedge sample_ntt_tb.clk)", 
                                                                 "tb/sample_ntt_tb.sv", 
                                                                 171);
            vlSelfRef.__Vm_traceActivity[4U] = 1U;
            while ((1U & ((~ (IData)(vlSelfRef.sample_ntt_tb__DOT__t_ready_o)) 
                          & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__done_seen))))) {
                co_await vlSelfRef.__VtrigSched_h7e082d28__0.trigger(0U, 
                                                                     vlProcess, 
                                                                     "@(posedge sample_ntt_tb.clk)", 
                                                                     "tb/sample_ntt_tb.sv", 
                                                                     172);
                vlSelfRef.__Vm_traceActivity[4U] = 1U;
            }
            if (vlSelfRef.sample_ntt_tb__DOT__done_seen) {
                goto __Vlabel1;
            }
            __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__byte_idx 
                = (__Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__byte_idx 
                   + __Vtask_sample_ntt_tb__DOT__drive_axi_sink__2__beat_size);
        }
        __Vlabel1: ;
    }
    co_await vlSelfRef.__VtrigSched_h7e082ce5__0.trigger(0U, 
                                                         vlProcess, 
                                                         "@(negedge sample_ntt_tb.clk)", 
                                                         "tb/sample_ntt_tb.sv", 
                                                         179);
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.sample_ntt_tb__DOT__t_valid_i = 0U;
    vlSelfRef.sample_ntt_tb__DOT__t_last_i = 0U;
    vlSelfRef.sample_ntt_tb__DOT__t_keep_i = 0U;
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[0U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[0U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[1U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[1U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[2U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[2U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[3U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[3U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[4U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[4U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[5U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[5U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[6U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[6U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[7U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[7U];
    while ((1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__done_seen)))) {
        co_await vlSelfRef.__VtrigSched_hdc05195c__0.trigger(1U, 
                                                             vlProcess, 
                                                             "@( sample_ntt_tb.done_seen)", 
                                                             "tb/sample_ntt_tb.sv", 
                                                             298);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    __Vfork_1__sync.done("tb/sample_ntt_tb.sv", 296);
    vlProcess->state(VlProcess::FINISHED);
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
}

void Vsample_ntt_tb___024root___act_comb__TOP__0(Vsample_ntt_tb___024root* vlSelf);

void Vsample_ntt_tb___024root___eval_act(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_act\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xdULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vsample_ntt_tb___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

VL_INLINE_OPT void Vsample_ntt_tb___024root___act_comb__TOP__0(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___act_comb__TOP__0\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr_nxt 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr;
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

void Vsample_ntt_tb___024root___nba_sequent__TOP__0(Vsample_ntt_tb___024root* vlSelf);
void Vsample_ntt_tb___024root___nba_sequent__TOP__1(Vsample_ntt_tb___024root* vlSelf);

void Vsample_ntt_tb___024root___eval_nba(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_nba\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsample_ntt_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsample_ntt_tb___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    if ((0xfULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsample_ntt_tb___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
    }
}

VL_INLINE_OPT void Vsample_ntt_tb___024root___nba_sequent__TOP__1(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___nba_sequent__TOP__1\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vdly__sample_ntt_tb__DOT__bp_cnt;
    __Vdly__sample_ntt_tb__DOT__bp_cnt = 0;
    IData/*31:0*/ __Vdly__sample_ntt_tb__DOT__observed_count;
    __Vdly__sample_ntt_tb__DOT__observed_count = 0;
    IData/*31:0*/ __Vdly__sample_ntt_tb__DOT__error_count;
    __Vdly__sample_ntt_tb__DOT__error_count = 0;
    IData/*31:0*/ __Vdly__sample_ntt_tb__DOT__cycle_cnt;
    __Vdly__sample_ntt_tb__DOT__cycle_cnt = 0;
    VlWide<8>/*255:0*/ __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0;
    VL_ZERO_W(256, __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0);
    CData/*1:0*/ __VdlyDim0__sample_ntt_tb__DOT__dut__DOT__wfifo__v0;
    __VdlyDim0__sample_ntt_tb__DOT__dut__DOT__wfifo__v0 = 0;
    CData/*0:0*/ __VdlySet__sample_ntt_tb__DOT__dut__DOT__wfifo__v0;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__wfifo__v0 = 0;
    CData/*0:0*/ __VdlySet__sample_ntt_tb__DOT__dut__DOT__agg__v0;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__agg__v0 = 0;
    SData/*11:0*/ __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v4;
    __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v4 = 0;
    CData/*0:0*/ __VdlySet__sample_ntt_tb__DOT__dut__DOT__agg__v4;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__agg__v4 = 0;
    SData/*11:0*/ __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v5;
    __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v5 = 0;
    SData/*11:0*/ __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v6;
    __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v6 = 0;
    SData/*11:0*/ __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v7;
    __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v7 = 0;
    CData/*0:0*/ __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq__v0;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq__v0 = 0;
    QData/*48:0*/ __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq__v2;
    __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq__v2 = 0;
    CData/*0:0*/ __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq__v2;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq__v2 = 0;
    QData/*48:0*/ __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq__v3;
    __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq__v3 = 0;
    CData/*0:0*/ __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq_valid__v0;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq_valid__v0 = 0;
    CData/*0:0*/ __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq_valid__v2;
    __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq_valid__v2 = 0;
    CData/*0:0*/ __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq_valid__v2;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq_valid__v2 = 0;
    CData/*0:0*/ __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq_valid__v3;
    __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq_valid__v3 = 0;
    VlWide<16>/*511:0*/ __Vtemp_1;
    // Body
    __Vdly__sample_ntt_tb__DOT__bp_cnt = vlSelfRef.sample_ntt_tb__DOT__bp_cnt;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq__v0 = 0U;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq__v2 = 0U;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__agg__v0 = 0U;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__agg__v4 = 0U;
    __Vdly__sample_ntt_tb__DOT__observed_count = vlSelfRef.sample_ntt_tb__DOT__observed_count;
    __Vdly__sample_ntt_tb__DOT__error_count = vlSelfRef.sample_ntt_tb__DOT__error_count;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__wfifo__v0 = 0U;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq_valid__v0 = 0U;
    __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq_valid__v2 = 0U;
    __Vdly__sample_ntt_tb__DOT__cycle_cnt = vlSelfRef.sample_ntt_tb__DOT__cycle_cnt;
    if (vlSelfRef.sample_ntt_tb__DOT__rst) {
        __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq__v0 = 1U;
        __VdlySet__sample_ntt_tb__DOT__dut__DOT__agg__v0 = 1U;
    } else {
        __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq__v2 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
            [0U];
        __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq__v2 = 1U;
        __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq__v3 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_nxt
            [1U];
        __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v4 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
            [0U];
        __VdlySet__sample_ntt_tb__DOT__dut__DOT__agg__v4 = 1U;
        __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v5 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
            [1U];
        __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v6 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
            [2U];
        __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v7 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_nxt
            [3U];
    }
    if (vlSelfRef.sample_ntt_tb__DOT__rst) {
        __Vdly__sample_ntt_tb__DOT__observed_count = 0U;
        __Vdly__sample_ntt_tb__DOT__error_count = 0U;
    } else if (VL_UNLIKELY(((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
                             [0U] & (IData)(vlSelfRef.sample_ntt_tb__DOT__t_ready_i))))) {
        vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__lane = 4U;
        if (VL_UNLIKELY(((0x3fU != (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
                                    [0U] ? 0x3fU : 0U))))) {
            __Vdly__sample_ntt_tb__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.sample_ntt_tb__DOT__error_count);
            VL_WRITEF_NX("ERROR [beat %0#]: t_keep_o = 0x%0x, expected 0x3F\n",0,
                         32,VL_SHIFTR_III(32,32,32, vlSelfRef.sample_ntt_tb__DOT__observed_count, 2U),
                         6,(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
                            [0U] ? 0x3fU : 0U));
        }
        if (VL_UNLIKELY((((0xfcU == vlSelfRef.sample_ntt_tb__DOT__observed_count) 
                          & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__t_last_o)))))) {
            VL_WRITEF_NX("ERROR: t_last_o not asserted on final beat\n",0);
            __Vdly__sample_ntt_tb__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.sample_ntt_tb__DOT__error_count);
        }
        if (VL_UNLIKELY((((0xfcU > vlSelfRef.sample_ntt_tb__DOT__observed_count) 
                          & (IData)(vlSelfRef.sample_ntt_tb__DOT__t_last_o))))) {
            VL_WRITEF_NX("ERROR: t_last_o asserted early at coeff index %0#\n",0,
                         32,vlSelfRef.sample_ntt_tb__DOT__observed_count);
            __Vdly__sample_ntt_tb__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.sample_ntt_tb__DOT__error_count);
        }
        vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got 
            = (0xfffU & (IData)((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
                                 [0U] >> 1U)));
        vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
            = vlSelfRef.sample_ntt_tb__DOT__observed_count;
        if (VL_UNLIKELY(((0x100U <= vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx)))) {
            VL_WRITEF_NX("ERROR: extra coefficient on lane 0\n",0);
            __Vdly__sample_ntt_tb__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.sample_ntt_tb__DOT__error_count);
        } else if (VL_UNLIKELY(((vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got 
                                 != (0xfffU & vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.at(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx)))))) {
            VL_WRITEF_NX("ERROR: Coeff[%0#] mismatch \342\200\224 got %0#, expected %0#\n",0,
                         32,vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx,
                         32,vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got,
                         32,vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.at(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx));
            __Vdly__sample_ntt_tb__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.sample_ntt_tb__DOT__error_count);
        }
        vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got 
            = (0xfffU & (IData)((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
                                 [0U] >> 0xdU)));
        vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
            = ((IData)(1U) + vlSelfRef.sample_ntt_tb__DOT__observed_count);
        if (VL_UNLIKELY(((0x100U <= vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx)))) {
            VL_WRITEF_NX("ERROR: extra coefficient on lane 1\n",0);
            __Vdly__sample_ntt_tb__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.sample_ntt_tb__DOT__error_count);
        } else if (VL_UNLIKELY(((vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got 
                                 != (0xfffU & vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.at(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx)))))) {
            VL_WRITEF_NX("ERROR: Coeff[%0#] mismatch \342\200\224 got %0#, expected %0#\n",0,
                         32,vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx,
                         32,vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got,
                         32,vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.at(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx));
            __Vdly__sample_ntt_tb__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.sample_ntt_tb__DOT__error_count);
        }
        vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got 
            = (0xfffU & (IData)((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
                                 [0U] >> 0x19U)));
        vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
            = ((IData)(2U) + vlSelfRef.sample_ntt_tb__DOT__observed_count);
        if (VL_UNLIKELY(((0x100U <= vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx)))) {
            VL_WRITEF_NX("ERROR: extra coefficient on lane 2\n",0);
            __Vdly__sample_ntt_tb__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.sample_ntt_tb__DOT__error_count);
        } else if (VL_UNLIKELY(((vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got 
                                 != (0xfffU & vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.at(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx)))))) {
            VL_WRITEF_NX("ERROR: Coeff[%0#] mismatch \342\200\224 got %0#, expected %0#\n",0,
                         32,vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx,
                         32,vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got,
                         32,vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.at(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx));
            __Vdly__sample_ntt_tb__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.sample_ntt_tb__DOT__error_count);
        }
        vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got 
            = (0xfffU & (IData)((vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
                                 [0U] >> 0x25U)));
        vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
            = ((IData)(3U) + vlSelfRef.sample_ntt_tb__DOT__observed_count);
        if (VL_UNLIKELY(((0x100U <= vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx)))) {
            VL_WRITEF_NX("ERROR: extra coefficient on lane 3\n",0);
            __Vdly__sample_ntt_tb__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.sample_ntt_tb__DOT__error_count);
        } else if (VL_UNLIKELY(((vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got 
                                 != (0xfffU & vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.at(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx)))))) {
            VL_WRITEF_NX("ERROR: Coeff[%0#] mismatch \342\200\224 got %0#, expected %0#\n",0,
                         32,vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx,
                         32,vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got,
                         32,vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.at(vlSelfRef.sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx));
            __Vdly__sample_ntt_tb__DOT__error_count 
                = ((IData)(1U) + vlSelfRef.sample_ntt_tb__DOT__error_count);
        }
        VL_WRITEF_NX("[TB] Output beat %0#: coeffs %0#-%0#  t_last=%0b\n",0,
                     32,VL_SHIFTR_III(32,32,32, vlSelfRef.sample_ntt_tb__DOT__observed_count, 2U),
                     32,vlSelfRef.sample_ntt_tb__DOT__observed_count,
                     32,((IData)(3U) + vlSelfRef.sample_ntt_tb__DOT__observed_count),
                     1,(IData)(vlSelfRef.sample_ntt_tb__DOT__t_last_o));
        __Vdly__sample_ntt_tb__DOT__observed_count 
            = ((IData)(4U) + vlSelfRef.sample_ntt_tb__DOT__observed_count);
    }
    if (vlSelfRef.sample_ntt_tb__DOT__rst) {
        __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq_valid__v0 = 1U;
    } else {
        __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq_valid__v2 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt
            [0U];
        __VdlySet__sample_ntt_tb__DOT__dut__DOT__oq_valid__v2 = 1U;
        __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq_valid__v3 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt
            [1U];
    }
    if ((1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__rst)))) {
        if (((IData)(vlSelfRef.sample_ntt_tb__DOT__t_valid_i) 
             & (IData)(vlSelfRef.sample_ntt_tb__DOT__t_ready_o))) {
            __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[0U] 
                = vlSelfRef.sample_ntt_tb__DOT__t_data_i[0U];
            __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[1U] 
                = vlSelfRef.sample_ntt_tb__DOT__t_data_i[1U];
            __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[2U] 
                = vlSelfRef.sample_ntt_tb__DOT__t_data_i[2U];
            __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[3U] 
                = vlSelfRef.sample_ntt_tb__DOT__t_data_i[3U];
            __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[4U] 
                = vlSelfRef.sample_ntt_tb__DOT__t_data_i[4U];
            __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[5U] 
                = vlSelfRef.sample_ntt_tb__DOT__t_data_i[5U];
            __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[6U] 
                = vlSelfRef.sample_ntt_tb__DOT__t_data_i[6U];
            __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[7U] 
                = vlSelfRef.sample_ntt_tb__DOT__t_data_i[7U];
            __VdlyDim0__sample_ntt_tb__DOT__dut__DOT__wfifo__v0 
                = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr;
            __VdlySet__sample_ntt_tb__DOT__dut__DOT__wfifo__v0 = 1U;
        }
    }
    if (vlSelfRef.sample_ntt_tb__DOT__rst) {
        __Vdly__sample_ntt_tb__DOT__cycle_cnt = 0U;
    } else {
        __Vdly__sample_ntt_tb__DOT__cycle_cnt = ((IData)(1U) 
                                                 + vlSelfRef.sample_ntt_tb__DOT__cycle_cnt);
        if (VL_UNLIKELY(((0U == VL_MODDIV_III(32, vlSelfRef.sample_ntt_tb__DOT__cycle_cnt, (IData)(0x1f4U)))))) {
            VL_WRITEF_NX("[DBG] cyc=%0# st=%0# wfifo=%0# coeff=%0# oq0v=%0b oq1v=%0b agg=%0# rdy=%0b val=%0b done=%0b\n",0,
                         32,vlSelfRef.sample_ntt_tb__DOT__cycle_cnt,
                         2,(IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state),
                         3,vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count,
                         9,(IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count),
                         1,vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
                         [0U],1,vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
                         [1U],3,vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count,
                         1,(IData)(vlSelfRef.sample_ntt_tb__DOT__t_ready_i),
                         1,vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
                         [0U],1,vlSelfRef.sample_ntt_tb__DOT__done);
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__rst)))) {
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_a 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_a_nxt;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_b 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_b_nxt;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_a 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_a_nxt;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_b 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_b_nxt;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[0U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[0U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[1U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[1U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[2U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[2U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[3U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[3U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[4U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[4U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[5U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[5U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[6U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[6U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[7U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt[7U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[0U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[0U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[1U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[1U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[2U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[2U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[3U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[3U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[4U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[4U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[5U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[5U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[6U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[6U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[7U] 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt[7U];
    }
    if (vlSelfRef.sample_ntt_tb__DOT__rst) {
        vlSelfRef.sample_ntt_tb__DOT__done_seen = 0U;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr = 0U;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff = 0U;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr = 0U;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count = 0U;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count = 0U;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state = 0U;
        vlSelfRef.sample_ntt_tb__DOT__t_ready_i = 0U;
        __Vdly__sample_ntt_tb__DOT__bp_cnt = 0U;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count = 0U;
    } else {
        if (vlSelfRef.sample_ntt_tb__DOT__done) {
            vlSelfRef.sample_ntt_tb__DOT__done_seen = 1U;
        }
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr_nxt;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff_nxt;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr_nxt;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state_nxt;
        __Vdly__sample_ntt_tb__DOT__bp_cnt = (3U & 
                                              ((IData)(1U) 
                                               + (IData)(vlSelfRef.sample_ntt_tb__DOT__bp_cnt)));
        vlSelfRef.sample_ntt_tb__DOT__t_ready_i = (0U 
                                                   != (IData)(vlSelfRef.sample_ntt_tb__DOT__bp_cnt));
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count 
            = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg_count_nxt;
    }
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v 
        = ((1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__rst))) 
           && (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w1v_nxt));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v 
        = ((1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__rst))) 
           && (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_w0v_nxt));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_av 
        = ((1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__rst))) 
           && (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_av_nxt));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_av 
        = ((1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__rst))) 
           && (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_av_nxt));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid 
        = ((1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__rst))) 
           && (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_valid_nxt));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_bv 
        = ((1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__rst))) 
           && (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d1_bv_nxt));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_bv 
        = ((1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__rst))) 
           && (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__s1_d2_bv_nxt));
    if (__VdlySet__sample_ntt_tb__DOT__dut__DOT__agg__v0) {
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[0U] = 0U;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[1U] = 0U;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[2U] = 0U;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[3U] = 0U;
    }
    if (__VdlySet__sample_ntt_tb__DOT__dut__DOT__agg__v4) {
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[0U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v4;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[1U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v5;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[2U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v6;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__agg[3U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__agg__v7;
    }
    vlSelfRef.sample_ntt_tb__DOT__observed_count = __Vdly__sample_ntt_tb__DOT__observed_count;
    vlSelfRef.sample_ntt_tb__DOT__error_count = __Vdly__sample_ntt_tb__DOT__error_count;
    if (__VdlySet__sample_ntt_tb__DOT__dut__DOT__oq__v0) {
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq[0U] = 0ULL;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq[1U] = 0ULL;
    }
    if (__VdlySet__sample_ntt_tb__DOT__dut__DOT__oq__v2) {
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq[0U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq__v2;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq[1U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq__v3;
    }
    if (__VdlySet__sample_ntt_tb__DOT__dut__DOT__wfifo__v0) {
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[__VdlyDim0__sample_ntt_tb__DOT__dut__DOT__wfifo__v0][0U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[0U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[__VdlyDim0__sample_ntt_tb__DOT__dut__DOT__wfifo__v0][1U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[1U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[__VdlyDim0__sample_ntt_tb__DOT__dut__DOT__wfifo__v0][2U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[2U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[__VdlyDim0__sample_ntt_tb__DOT__dut__DOT__wfifo__v0][3U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[3U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[__VdlyDim0__sample_ntt_tb__DOT__dut__DOT__wfifo__v0][4U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[4U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[__VdlyDim0__sample_ntt_tb__DOT__dut__DOT__wfifo__v0][5U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[5U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[__VdlyDim0__sample_ntt_tb__DOT__dut__DOT__wfifo__v0][6U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[6U];
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo[__VdlyDim0__sample_ntt_tb__DOT__dut__DOT__wfifo__v0][7U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__wfifo__v0[7U];
    }
    vlSelfRef.sample_ntt_tb__DOT__cycle_cnt = __Vdly__sample_ntt_tb__DOT__cycle_cnt;
    if (__VdlySet__sample_ntt_tb__DOT__dut__DOT__oq_valid__v0) {
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid[0U] = 0U;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid[1U] = 0U;
    }
    if (__VdlySet__sample_ntt_tb__DOT__dut__DOT__oq_valid__v2) {
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid[0U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq_valid__v2;
        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid[1U] 
            = __VdlyVal__sample_ntt_tb__DOT__dut__DOT__oq_valid__v3;
    }
    vlSelfRef.sample_ntt_tb__DOT__t_ready_o = ((1U 
                                                & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__rst))) 
                                               && ((1U 
                                                    == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state_nxt)) 
                                                   & (4U 
                                                      > (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt))));
    vlSelfRef.sample_ntt_tb__DOT__t_last_o = (vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid
                                              [0U] 
                                              & (IData)(
                                                        vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq
                                                        [0U]));
    vlSelfRef.sample_ntt_tb__DOT__done = ((1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__rst))) 
                                          && (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__done_nxt));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr 
        = ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_boff) 
           << 3U);
    __Vtemp_1[0U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[0U];
    __Vtemp_1[1U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[1U];
    __Vtemp_1[2U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[2U];
    __Vtemp_1[3U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[3U];
    __Vtemp_1[4U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[4U];
    __Vtemp_1[5U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[5U];
    __Vtemp_1[6U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[6U];
    __Vtemp_1[7U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word0[7U];
    __Vtemp_1[8U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[0U];
    __Vtemp_1[9U] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[1U];
    __Vtemp_1[0xaU] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[2U];
    __Vtemp_1[0xbU] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[3U];
    __Vtemp_1[0xcU] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[4U];
    __Vtemp_1[0xdU] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[5U];
    __Vtemp_1[0xeU] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[6U];
    __Vtemp_1[0xfU] = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_word1[7U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__six_bytes 
        = (0xffffffffffffULL & (((QData)((IData)(__Vtemp_1[
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
                                                               __Vtemp_1[
                                                               (((IData)(0x1fU) 
                                                                 + (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr)) 
                                                                >> 5U)])) 
                                               << ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr))))) 
                                   | ((QData)((IData)(
                                                      __Vtemp_1[
                                                      ((IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr) 
                                                       >> 5U)])) 
                                      >> (0x1fU & (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr))))));
    vlSelfRef.sample_ntt_tb__DOT__bp_cnt = __Vdly__sample_ntt_tb__DOT__bp_cnt;
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
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT__done_nxt = 0U;
    if ((0U != (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state))) {
        if ((1U != (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state))) {
            if ((2U == (IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__state))) {
                vlSelfRef.sample_ntt_tb__DOT__dut__DOT__done_nxt = 1U;
            }
        }
    }
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
}

void Vsample_ntt_tb___024root___timing_resume(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___timing_resume\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h7e082d28__0.resume(
                                                   "@(posedge sample_ntt_tb.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h7e082ce5__0.resume(
                                                   "@(negedge sample_ntt_tb.clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hdc05195c__0.resume(
                                                   "@( sample_ntt_tb.done_seen)");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vsample_ntt_tb___024root___timing_commit(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___timing_commit\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h7e082d28__0.commit(
                                                   "@(posedge sample_ntt_tb.clk)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h7e082ce5__0.commit(
                                                   "@(negedge sample_ntt_tb.clk)");
    }
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hdc05195c__0.commit(
                                                   "@( sample_ntt_tb.done_seen)");
    }
}

void Vsample_ntt_tb___024root___eval_triggers__act(Vsample_ntt_tb___024root* vlSelf);

bool Vsample_ntt_tb___024root___eval_phase__act(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_phase__act\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<5> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsample_ntt_tb___024root___eval_triggers__act(vlSelf);
    Vsample_ntt_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vsample_ntt_tb___024root___timing_resume(vlSelf);
        Vsample_ntt_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsample_ntt_tb___024root___eval_phase__nba(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_phase__nba\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsample_ntt_tb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsample_ntt_tb___024root___dump_triggers__nba(Vsample_ntt_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsample_ntt_tb___024root___dump_triggers__act(Vsample_ntt_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsample_ntt_tb___024root___eval(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__rst 
        = vlSelfRef.sample_ntt_tb__DOT__rst;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__wfifo_count 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__coeff_count 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_0_0 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_0_0;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[0U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[0U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[1U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[1U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[2U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[2U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[3U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[3U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[4U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[4U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[5U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[5U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[6U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[6U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[7U] 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[7U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[0U] 
        = vlSelfRef.sample_ntt_tb__DOT__t_data_i[0U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[1U] 
        = vlSelfRef.sample_ntt_tb__DOT__t_data_i[1U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[2U] 
        = vlSelfRef.sample_ntt_tb__DOT__t_data_i[2U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[3U] 
        = vlSelfRef.sample_ntt_tb__DOT__t_data_i[3U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[4U] 
        = vlSelfRef.sample_ntt_tb__DOT__t_data_i[4U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[5U] 
        = vlSelfRef.sample_ntt_tb__DOT__t_data_i[5U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[6U] 
        = vlSelfRef.sample_ntt_tb__DOT__t_data_i[6U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[7U] 
        = vlSelfRef.sample_ntt_tb__DOT__t_data_i[7U];
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_2_0 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_2_0;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_keep_i 
        = vlSelfRef.sample_ntt_tb__DOT__t_keep_i;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_3_0 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_3_0;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_last_i 
        = vlSelfRef.sample_ntt_tb__DOT__t_last_i;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_4_0 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_4_0;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_5_0 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_5_0;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__oq 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_6_0 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_6_0;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__oq_valid 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT__oq_valid;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_7_0 
        = vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_7_0;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_last_o 
        = vlSelfRef.sample_ntt_tb__DOT__t_last_o;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_valid_i 
        = vlSelfRef.sample_ntt_tb__DOT__t_valid_i;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_ready_o 
        = vlSelfRef.sample_ntt_tb__DOT__t_ready_o;
    vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_ready_i 
        = vlSelfRef.sample_ntt_tb__DOT__t_ready_i;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsample_ntt_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/sample_ntt_tb.sv", 20, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsample_ntt_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/sample_ntt_tb.sv", 20, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vsample_ntt_tb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vsample_ntt_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsample_ntt_tb___024root___eval_debug_assertions(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_debug_assertions\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
