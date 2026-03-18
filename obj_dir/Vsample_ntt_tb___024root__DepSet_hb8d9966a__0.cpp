// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsample_ntt_tb.h for the primary calling header

#include "Vsample_ntt_tb__pch.h"
#include "Vsample_ntt_tb__Syms.h"
#include "Vsample_ntt_tb___024root.h"

extern const VlWide<8>/*255:0*/ Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0;
VlCoroutine Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__0(Vsample_ntt_tb___024root* vlSelf, VlProcessRef vlProcess, VlForkSync __Vfork_1__sync);
VlCoroutine Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__1(Vsample_ntt_tb___024root* vlSelf, VlProcessRef vlProcess, VlForkSync __Vfork_1__sync);

VL_INLINE_OPT VlCoroutine Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__0(Vsample_ntt_tb___024root* vlSelf, VlProcessRef vlProcess) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vtask_sample_ntt_tb__DOT__generate_stimulus__0__unnamedblk1__DOT__i;
    __Vtask_sample_ntt_tb__DOT__generate_stimulus__0__unnamedblk1__DOT__i = 0;
    IData/*31:0*/ __Vtask_sample_ntt_tb__DOT__generate_stimulus__0__seed;
    __Vtask_sample_ntt_tb__DOT__generate_stimulus__0__seed = 0;
    IData/*31:0*/ __Vtask_sample_ntt_tb__DOT__build_golden_model__1__idx;
    __Vtask_sample_ntt_tb__DOT__build_golden_model__1__idx = 0;
    IData/*31:0*/ __Vtask_sample_ntt_tb__DOT__build_golden_model__1__d1;
    __Vtask_sample_ntt_tb__DOT__build_golden_model__1__d1 = 0;
    IData/*31:0*/ __Vtask_sample_ntt_tb__DOT__build_golden_model__1__d2;
    __Vtask_sample_ntt_tb__DOT__build_golden_model__1__d2 = 0;
    // Body
    vlSelfRef.sample_ntt_tb__DOT__rst = 1U;
    vlSelfRef.sample_ntt_tb__DOT__start = 0U;
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[0U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[0U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[1U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[1U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[2U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[2U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[3U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[3U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[4U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[4U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[5U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[5U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[6U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[6U];
    vlSelfRef.sample_ntt_tb__DOT__t_data_i[7U] = Vsample_ntt_tb__ConstPool__CONST_h9e67c271_0[7U];
    vlSelfRef.sample_ntt_tb__DOT__t_valid_i = 0U;
    vlSelfRef.sample_ntt_tb__DOT__t_last_i = 0U;
    vlSelfRef.sample_ntt_tb__DOT__t_keep_i = 0U;
    __Vtask_sample_ntt_tb__DOT__generate_stimulus__0__seed = 0x5a1c2026U;
    vlSelfRef.sample_ntt_tb__DOT__stimulus_bytes.clear();
    __Vtask_sample_ntt_tb__DOT__generate_stimulus__0__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, __Vtask_sample_ntt_tb__DOT__generate_stimulus__0__unnamedblk1__DOT__i)) {
        vlSelfRef.sample_ntt_tb__DOT__stimulus_bytes.push_back(
                                                               (0xffU 
                                                                & VL_URANDOM_SEEDED_II(__Vtask_sample_ntt_tb__DOT__generate_stimulus__0__seed)));
        __Vtask_sample_ntt_tb__DOT__generate_stimulus__0__seed 
            = ((IData)(0x9e37U) + __Vtask_sample_ntt_tb__DOT__generate_stimulus__0__seed);
        __Vtask_sample_ntt_tb__DOT__generate_stimulus__0__unnamedblk1__DOT__i 
            = ((IData)(1U) + __Vtask_sample_ntt_tb__DOT__generate_stimulus__0__unnamedblk1__DOT__i);
    }
    __Vtask_sample_ntt_tb__DOT__build_golden_model__1__d1 = 0;
    __Vtask_sample_ntt_tb__DOT__build_golden_model__1__d2 = 0;
    vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.clear();
    __Vtask_sample_ntt_tb__DOT__build_golden_model__1__idx = 0U;
    while ((VL_LTS_III(32, ((IData)(2U) + __Vtask_sample_ntt_tb__DOT__build_golden_model__1__idx), vlSelfRef.sample_ntt_tb__DOT__stimulus_bytes.size()) 
            & VL_GTS_III(32, 0x100U, vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.size()))) {
        __Vtask_sample_ntt_tb__DOT__build_golden_model__1__d1 
            = (vlSelfRef.sample_ntt_tb__DOT__stimulus_bytes.at(__Vtask_sample_ntt_tb__DOT__build_golden_model__1__idx) 
               + (0xf00U & VL_SHIFTL_III(32,32,32, vlSelfRef.sample_ntt_tb__DOT__stimulus_bytes.at(
                                                                                ((IData)(1U) 
                                                                                + __Vtask_sample_ntt_tb__DOT__build_golden_model__1__idx)), 8U)));
        __Vtask_sample_ntt_tb__DOT__build_golden_model__1__d2 
            = ((0xfU & VL_SHIFTR_III(32,32,32, vlSelfRef.sample_ntt_tb__DOT__stimulus_bytes.at(
                                                                                ((IData)(1U) 
                                                                                + __Vtask_sample_ntt_tb__DOT__build_golden_model__1__idx)), 4U)) 
               + VL_SHIFTL_III(32,32,32, vlSelfRef.sample_ntt_tb__DOT__stimulus_bytes.at(
                                                                                ((IData)(2U) 
                                                                                + __Vtask_sample_ntt_tb__DOT__build_golden_model__1__idx)), 4U));
        if ((VL_GTS_III(32, 0xd01U, __Vtask_sample_ntt_tb__DOT__build_golden_model__1__d1) 
             & VL_GTS_III(32, 0x100U, vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.size()))) {
            vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.push_back(__Vtask_sample_ntt_tb__DOT__build_golden_model__1__d1);
        }
        if ((VL_GTS_III(32, 0xd01U, __Vtask_sample_ntt_tb__DOT__build_golden_model__1__d2) 
             & VL_GTS_III(32, 0x100U, vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.size()))) {
            vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.push_back(__Vtask_sample_ntt_tb__DOT__build_golden_model__1__d2);
        }
        __Vtask_sample_ntt_tb__DOT__build_golden_model__1__idx 
            = ((IData)(3U) + __Vtask_sample_ntt_tb__DOT__build_golden_model__1__idx);
    }
    if (VL_UNLIKELY(((0x100U != vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: sample_ntt_tb.sv:143: Assertion failed in %Nsample_ntt_tb.build_golden_model: Golden model only produced %0d coeffs \342\200\224 increase NUM_BYTES.\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     32,vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.size());
        VL_STOP_MT("tb/sample_ntt_tb.sv", 143, "", false);
    }
    VL_WRITEF_NX("[TB] Golden model built: %0d coefficients from %0d bytes.\n",0,
                 32,vlSelfRef.sample_ntt_tb__DOT__golden_coeffs.size(),
                 32,vlSelfRef.sample_ntt_tb__DOT__stimulus_bytes.size());
    co_await vlSelfRef.__VtrigSched_h7e082d28__0.trigger(0U, 
                                                         vlProcess, 
                                                         "@(posedge sample_ntt_tb.clk)", 
                                                         "tb/sample_ntt_tb.sv", 
                                                         285);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h7e082d28__0.trigger(0U, 
                                                         vlProcess, 
                                                         "@(posedge sample_ntt_tb.clk)", 
                                                         "tb/sample_ntt_tb.sv", 
                                                         285);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h7e082d28__0.trigger(0U, 
                                                         vlProcess, 
                                                         "@(posedge sample_ntt_tb.clk)", 
                                                         "tb/sample_ntt_tb.sv", 
                                                         285);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h7e082d28__0.trigger(0U, 
                                                         vlProcess, 
                                                         "@(posedge sample_ntt_tb.clk)", 
                                                         "tb/sample_ntt_tb.sv", 
                                                         285);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h7e082d28__0.trigger(0U, 
                                                         vlProcess, 
                                                         "@(posedge sample_ntt_tb.clk)", 
                                                         "tb/sample_ntt_tb.sv", 
                                                         285);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.sample_ntt_tb__DOT__rst = 0U;
    co_await vlSelfRef.__VtrigSched_h7e082ce5__0.trigger(0U, 
                                                         vlProcess, 
                                                         "@(negedge sample_ntt_tb.clk)", 
                                                         "tb/sample_ntt_tb.sv", 
                                                         289);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.sample_ntt_tb__DOT__start = 1U;
    co_await vlSelfRef.__VtrigSched_h7e082ce5__0.trigger(0U, 
                                                         vlProcess, 
                                                         "@(negedge sample_ntt_tb.clk)", 
                                                         "tb/sample_ntt_tb.sv", 
                                                         291);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.sample_ntt_tb__DOT__start = 0U;
    VlForkSync __Vfork_1__sync;
    __Vfork_1__sync.init(1U, vlProcess);
    Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__0(vlSelf, std::make_shared<VlProcess>(vlProcess), __Vfork_1__sync);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__1(vlSelf, std::make_shared<VlProcess>(vlProcess), __Vfork_1__sync);
    co_await __Vfork_1__sync.join(vlProcess, "tb/sample_ntt_tb.sv", 
                                  295);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlProcess->disableFork();
    co_await vlSelfRef.__VtrigSched_h7e082d28__0.trigger(0U, 
                                                         vlProcess, 
                                                         "@(posedge sample_ntt_tb.clk)", 
                                                         "tb/sample_ntt_tb.sv", 
                                                         307);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((0x100U != vlSelfRef.sample_ntt_tb__DOT__observed_count)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: sample_ntt_tb.sv:311: Assertion failed in %Nsample_ntt_tb: FAIL: observed %0# coefficients, expected 256\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     32,vlSelfRef.sample_ntt_tb__DOT__observed_count);
        VL_STOP_MT("tb/sample_ntt_tb.sv", 311, "", false);
    }
    if (VL_UNLIKELY(((0U != vlSelfRef.sample_ntt_tb__DOT__error_count)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: sample_ntt_tb.sv:315: Assertion failed in %Nsample_ntt_tb: FAIL: %0# mismatches detected\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     32,vlSelfRef.sample_ntt_tb__DOT__error_count);
        VL_STOP_MT("tb/sample_ntt_tb.sv", 315, "", false);
    }
    VL_WRITEF_NX("PASS: sample_ntt produced 256 coefficients matching the golden model.\n",0);
    VL_FINISH_MT("tb/sample_ntt_tb.sv", 319, "");
    vlProcess->state(VlProcess::FINISHED);
    co_return;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__1(Vsample_ntt_tb___024root* vlSelf, VlProcessRef vlProcess, VlForkSync __Vfork_1__sync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__1\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vtask_sample_ntt_tb__DOT____Vfork_begin_watchdog__0__3__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_sample_ntt_tb__DOT____Vfork_begin_watchdog__0__3__unnamedblk1_2__DOT____Vrepeat1 = 0;
    // Body
    __Vtask_sample_ntt_tb__DOT____Vfork_begin_watchdog__0__3__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_sample_ntt_tb__DOT____Vfork_begin_watchdog__0__3__unnamedblk1_2__DOT____Vrepeat1 = 0xc350U;
    while (VL_LTS_III(32, 0U, __Vtask_sample_ntt_tb__DOT____Vfork_begin_watchdog__0__3__unnamedblk1_2__DOT____Vrepeat1)) {
        co_await vlSelfRef.__VtrigSched_h7e082d28__0.trigger(0U, 
                                                             vlProcess, 
                                                             "@(posedge sample_ntt_tb.clk)", 
                                                             "tb/sample_ntt_tb.sv", 
                                                             301);
        __Vtask_sample_ntt_tb__DOT____Vfork_begin_watchdog__0__3__unnamedblk1_2__DOT____Vrepeat1 
            = (__Vtask_sample_ntt_tb__DOT____Vfork_begin_watchdog__0__3__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    VL_WRITEF_NX("[%0t] %%Fatal: sample_ntt_tb.sv:302: Assertion failed in %Nsample_ntt_tb.__Vfork_begin_watchdog__0: TIMEOUT: DUT did not assert done within 50 000 cycles\n",0,
                 64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
    VL_STOP_MT("tb/sample_ntt_tb.sv", 302, "", false);
    __Vfork_1__sync.done("tb/sample_ntt_tb.sv", 300);
    vlProcess->state(VlProcess::FINISHED);
}

VL_INLINE_OPT VlCoroutine Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__1(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb/sample_ntt_tb.sv", 
                                             107);
        vlSelfRef.sample_ntt_tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.sample_ntt_tb__DOT__clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsample_ntt_tb___024root___dump_triggers__act(Vsample_ntt_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsample_ntt_tb___024root___eval_triggers__act(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___eval_triggers__act\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.sample_ntt_tb__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSelfRef.sample_ntt_tb__DOT__rst) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__rst__0))));
    vlSelfRef.__VactTriggered.setBit(2U, ((~ (IData)(vlSelfRef.sample_ntt_tb__DOT__clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__clk__0)));
    vlSelfRef.__VactTriggered.setBit(3U, ((IData)(vlSelfRef.sample_ntt_tb__DOT__done_seen) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__done_seen__0)));
    vlSelfRef.__VactTriggered.setBit(4U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__clk__0 
        = vlSelfRef.sample_ntt_tb__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__rst__0 
        = vlSelfRef.sample_ntt_tb__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__sample_ntt_tb__DOT__done_seen__0 
        = vlSelfRef.sample_ntt_tb__DOT__done_seen;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(3U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsample_ntt_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vsample_ntt_tb___024root___nba_sequent__TOP__0(Vsample_ntt_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsample_ntt_tb___024root___nba_sequent__TOP__0\n"); );
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__rst) 
                                   | ((~ (IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_0_0)) 
                                      | (((0U == ((
                                                   ((((((vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[0U] 
                                                         ^ 
                                                         vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[0U]) 
                                                        | (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[1U] 
                                                           ^ 
                                                           vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[1U])) 
                                                       | (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[2U] 
                                                          ^ 
                                                          vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[2U])) 
                                                      | (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[3U] 
                                                         ^ 
                                                         vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[3U])) 
                                                     | (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[4U] 
                                                        ^ 
                                                        vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[4U])) 
                                                    | (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[5U] 
                                                       ^ 
                                                       vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[5U])) 
                                                   | (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[6U] 
                                                      ^ 
                                                      vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[6U])) 
                                                  | (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[7U] 
                                                     ^ 
                                                     vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[7U]))) 
                                          & (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_2_0 
                                             == vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_keep_i)) 
                                         & ((IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_3_0) 
                                            == (IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_last_i)))))))))) {
            VL_WRITEF_NX("[%0t] %%Error: sample_ntt.sv:637: Assertion failed in %Nsample_ntt_tb.dut: AXI sink: signals changed during backpressure\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name());
            VL_STOP_MT("rtl/sample_ntt.sv", 637, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__rst) 
                                   | ((~ (IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_4_0)) 
                                      | (((vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_5_0 
                                           == (0xffffffffffffULL 
                                               & (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__oq
                                                  [0U] 
                                                  >> 1U))) 
                                          & ((IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_6_0) 
                                             == (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__oq_valid
                                                 [0U]
                                                  ? 0x3fU
                                                  : 0U))) 
                                         & ((IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_7_0) 
                                            == (IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_last_o)))))))))) {
            VL_WRITEF_NX("[%0t] %%Error: sample_ntt.sv:642: Assertion failed in %Nsample_ntt_tb.dut: AXI source: signals changed during backpressure\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name());
            VL_STOP_MT("rtl/sample_ntt.sv", 642, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__rst) 
                                   | (0x100U >= (IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__coeff_count)))))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: sample_ntt.sv:632: Assertion failed in %Nsample_ntt_tb.dut: coeff_count overflow: %0#\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name(),9,(IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__coeff_count));
            VL_STOP_MT("rtl/sample_ntt.sv", 632, "", false);
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__rst) 
                                   | (4U >= (IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__wfifo_count)))))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: sample_ntt.sv:628: Assertion failed in %Nsample_ntt_tb.dut: FIFO count overflow: %0#\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name(),3,(IData)(vlSelfRef.sample_ntt_tb__DOT__dut__DOT__wfifo_count));
            VL_STOP_MT("rtl/sample_ntt.sv", 628, "", false);
        }
    }
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[0U] 
        = vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[0U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[1U] 
        = vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[1U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[2U] 
        = vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[2U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[3U] 
        = vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[3U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[4U] 
        = vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[4U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[5U] 
        = vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[5U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[6U] 
        = vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[6U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_1_0[7U] 
        = vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_data_i[7U];
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_2_0 
        = vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_keep_i;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_3_0 
        = vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_last_i;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_5_0 
        = (0xffffffffffffULL & (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__oq
                                [0U] >> 1U));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_7_0 
        = vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_last_o;
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_6_0 
        = (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__oq_valid
           [0U] ? 0x3fU : 0U);
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_0_0 
        = ((~ (IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__rst)) 
           & ((IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_valid_i) 
              & (~ (IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_ready_o))));
    vlSelfRef.sample_ntt_tb__DOT__dut__DOT___Vpast_4_0 
        = ((~ (IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__rst)) 
           & (vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__oq_valid
              [0U] & (~ (IData)(vlSelfRef.__Vsampled_TOP__sample_ntt_tb__DOT__t_ready_i))));
}
