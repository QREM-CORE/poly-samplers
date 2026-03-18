// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsample_ntt_tb.h for the primary calling header

#ifndef VERILATED_VSAMPLE_NTT_TB___024ROOT_H_
#define VERILATED_VSAMPLE_NTT_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsample_ntt_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsample_ntt_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ sample_ntt_tb__DOT__clk;
        CData/*0:0*/ sample_ntt_tb__DOT__rst;
        CData/*0:0*/ sample_ntt_tb__DOT__start;
        CData/*0:0*/ sample_ntt_tb__DOT__done;
        CData/*0:0*/ sample_ntt_tb__DOT__t_valid_i;
        CData/*0:0*/ sample_ntt_tb__DOT__t_last_i;
        CData/*0:0*/ sample_ntt_tb__DOT__t_ready_o;
        CData/*0:0*/ sample_ntt_tb__DOT__t_last_o;
        CData/*0:0*/ sample_ntt_tb__DOT__t_ready_i;
        CData/*0:0*/ sample_ntt_tb__DOT__done_seen;
        CData/*1:0*/ sample_ntt_tb__DOT__bp_cnt;
        CData/*1:0*/ sample_ntt_tb__DOT__dut__DOT__state;
        CData/*1:0*/ sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr;
        CData/*1:0*/ sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr;
        CData/*2:0*/ sample_ntt_tb__DOT__dut__DOT__wfifo_count;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__gbx_w0v;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__gbx_w1v;
        CData/*4:0*/ sample_ntt_tb__DOT__dut__DOT__gbx_boff;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s1_valid;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d1_av;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d2_av;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d1_bv;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d2_bv;
        CData/*2:0*/ sample_ntt_tb__DOT__dut__DOT__agg_count;
        CData/*7:0*/ sample_ntt_tb__DOT__dut__DOT__b0_a;
        CData/*7:0*/ sample_ntt_tb__DOT__dut__DOT__b1_a;
        CData/*7:0*/ sample_ntt_tb__DOT__dut__DOT__b2_a;
        CData/*7:0*/ sample_ntt_tb__DOT__dut__DOT__b0_b;
        CData/*7:0*/ sample_ntt_tb__DOT__dut__DOT__b1_b;
        CData/*7:0*/ sample_ntt_tb__DOT__dut__DOT__b2_b;
        CData/*2:0*/ sample_ntt_tb__DOT__dut__DOT__s1_accepted;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s1_will_emit;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__oq_full;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s1_stall;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__pipe_advance;
        CData/*1:0*/ sample_ntt_tb__DOT__dut__DOT__state_nxt;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__done_nxt;
        CData/*1:0*/ sample_ntt_tb__DOT__dut__DOT__wfifo_wr_ptr_nxt;
        CData/*1:0*/ sample_ntt_tb__DOT__dut__DOT__wfifo_rd_ptr_nxt;
        CData/*2:0*/ sample_ntt_tb__DOT__dut__DOT__wfifo_count_nxt;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__gbx_w0v_nxt;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__gbx_w1v_nxt;
        CData/*4:0*/ sample_ntt_tb__DOT__dut__DOT__gbx_boff_nxt;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s1_valid_nxt;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d1_av_nxt;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d2_av_nxt;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d1_bv_nxt;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d2_bv_nxt;
        CData/*2:0*/ sample_ntt_tb__DOT__dut__DOT__agg_count_nxt;
        CData/*5:0*/ sample_ntt_tb__DOT__dut__DOT__boff_plus6;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s0_d1_av;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s0_d2_av;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s0_d1_bv;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT__s0_d2_bv;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT___Vpast_0_0;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT___Vpast_3_0;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT___Vpast_4_0;
        CData/*5:0*/ sample_ntt_tb__DOT__dut__DOT___Vpast_6_0;
        CData/*0:0*/ sample_ntt_tb__DOT__dut__DOT___Vpast_7_0;
        CData/*0:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__rst;
        CData/*2:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__wfifo_count;
        CData/*0:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_0_0;
        CData/*0:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_3_0;
        CData/*0:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__t_last_i;
    };
    struct {
        CData/*0:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_4_0;
        CData/*5:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_6_0;
        CData/*0:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_7_0;
        CData/*0:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__t_last_o;
        CData/*0:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__t_valid_i;
        CData/*0:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__t_ready_o;
        CData/*0:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__t_ready_i;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__sample_ntt_tb__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__sample_ntt_tb__DOT__rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__sample_ntt_tb__DOT__done_seen__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d1_a;
        SData/*11:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d2_a;
        SData/*11:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d1_b;
        SData/*11:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d2_b;
        SData/*8:0*/ sample_ntt_tb__DOT__dut__DOT__coeff_count;
        SData/*8:0*/ sample_ntt_tb__DOT__dut__DOT__gbx_bit_ptr;
        SData/*11:0*/ sample_ntt_tb__DOT__dut__DOT__d1_a;
        SData/*11:0*/ sample_ntt_tb__DOT__dut__DOT__d2_a;
        SData/*11:0*/ sample_ntt_tb__DOT__dut__DOT__d1_b;
        SData/*11:0*/ sample_ntt_tb__DOT__dut__DOT__d2_b;
        SData/*11:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d1_a_nxt;
        SData/*11:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d2_a_nxt;
        SData/*11:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d1_b_nxt;
        SData/*11:0*/ sample_ntt_tb__DOT__dut__DOT__s1_d2_b_nxt;
        SData/*8:0*/ sample_ntt_tb__DOT__dut__DOT__coeff_count_nxt;
        SData/*8:0*/ sample_ntt_tb__DOT__dut__DOT__cnt_base;
        SData/*8:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__coeff_count;
        VlWide<8>/*255:0*/ sample_ntt_tb__DOT__t_data_i;
        IData/*31:0*/ sample_ntt_tb__DOT__t_keep_i;
        IData/*31:0*/ sample_ntt_tb__DOT__observed_count;
        IData/*31:0*/ sample_ntt_tb__DOT__error_count;
        IData/*31:0*/ sample_ntt_tb__DOT__cycle_cnt;
        IData/*31:0*/ sample_ntt_tb__DOT__unnamedblk3__DOT__lane;
        IData/*31:0*/ sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__got;
        IData/*31:0*/ sample_ntt_tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx;
        VlWide<8>/*255:0*/ sample_ntt_tb__DOT__dut__DOT__gbx_word0;
        VlWide<8>/*255:0*/ sample_ntt_tb__DOT__dut__DOT__gbx_word1;
        VlWide<8>/*255:0*/ sample_ntt_tb__DOT__dut__DOT__gbx_word0_nxt;
        VlWide<8>/*255:0*/ sample_ntt_tb__DOT__dut__DOT__gbx_word1_nxt;
        VlWide<8>/*255:0*/ sample_ntt_tb__DOT__dut__DOT___Vpast_1_0;
        IData/*31:0*/ sample_ntt_tb__DOT__dut__DOT___Vpast_2_0;
        VlWide<8>/*255:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_1_0;
        VlWide<8>/*255:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__t_data_i;
        IData/*31:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_2_0;
        IData/*31:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__t_keep_i;
        IData/*31:0*/ __VactIterCount;
        QData/*47:0*/ sample_ntt_tb__DOT__dut__DOT__six_bytes;
        QData/*47:0*/ sample_ntt_tb__DOT__dut__DOT___Vpast_5_0;
        QData/*47:0*/ __Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT___Vpast_5_0;
        VlUnpacked<VlWide<8>/*255:0*/, 4> sample_ntt_tb__DOT__dut__DOT__wfifo;
        VlUnpacked<SData/*11:0*/, 4> sample_ntt_tb__DOT__dut__DOT__agg;
        VlUnpacked<QData/*48:0*/, 2> sample_ntt_tb__DOT__dut__DOT__oq;
        VlUnpacked<CData/*0:0*/, 2> sample_ntt_tb__DOT__dut__DOT__oq_valid;
        VlUnpacked<SData/*11:0*/, 4> sample_ntt_tb__DOT__dut__DOT__agg_nxt;
        VlUnpacked<QData/*48:0*/, 2> sample_ntt_tb__DOT__dut__DOT__oq_nxt;
        VlUnpacked<CData/*0:0*/, 2> sample_ntt_tb__DOT__dut__DOT__oq_valid_nxt;
        VlUnpacked<QData/*48:0*/, 2> __Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__oq;
        VlUnpacked<CData/*0:0*/, 2> __Vsampled_TOP__sample_ntt_tb__DOT__dut__DOT__oq_valid;
        VlUnpacked<CData/*0:0*/, 8> __Vm_traceActivity;
    };
    VlQueue<CData/*7:0*/> sample_ntt_tb__DOT__stimulus_bytes;
    VlQueue<IData/*31:0*/> sample_ntt_tb__DOT__golden_coeffs;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h7e082d28__0;
    VlTriggerScheduler __VtrigSched_h7e082ce5__0;
    VlTriggerScheduler __VtrigSched_hdc05195c__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<5> __VactTriggered;
    VlTriggerVec<5> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsample_ntt_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsample_ntt_tb___024root(Vsample_ntt_tb__Syms* symsp, const char* v__name);
    ~Vsample_ntt_tb___024root();
    VL_UNCOPYABLE(Vsample_ntt_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
