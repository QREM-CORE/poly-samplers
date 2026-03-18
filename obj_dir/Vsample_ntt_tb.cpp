// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsample_ntt_tb__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsample_ntt_tb::Vsample_ntt_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsample_ntt_tb__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vsample_ntt_tb::Vsample_ntt_tb(const char* _vcname__)
    : Vsample_ntt_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsample_ntt_tb::~Vsample_ntt_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsample_ntt_tb___024root___eval_debug_assertions(Vsample_ntt_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vsample_ntt_tb___024root___eval_static(Vsample_ntt_tb___024root* vlSelf);
void Vsample_ntt_tb___024root___eval_initial(Vsample_ntt_tb___024root* vlSelf);
void Vsample_ntt_tb___024root___eval_settle(Vsample_ntt_tb___024root* vlSelf);
void Vsample_ntt_tb___024root___eval(Vsample_ntt_tb___024root* vlSelf);

void Vsample_ntt_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsample_ntt_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsample_ntt_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsample_ntt_tb___024root___eval_static(&(vlSymsp->TOP));
        Vsample_ntt_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vsample_ntt_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsample_ntt_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsample_ntt_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vsample_ntt_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vsample_ntt_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsample_ntt_tb___024root___eval_final(Vsample_ntt_tb___024root* vlSelf);

VL_ATTR_COLD void Vsample_ntt_tb::final() {
    Vsample_ntt_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsample_ntt_tb::hierName() const { return vlSymsp->name(); }
const char* Vsample_ntt_tb::modelName() const { return "Vsample_ntt_tb"; }
unsigned Vsample_ntt_tb::threads() const { return 1; }
void Vsample_ntt_tb::prepareClone() const { contextp()->prepareClone(); }
void Vsample_ntt_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vsample_ntt_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsample_ntt_tb___024root__trace_decl_types(VerilatedVcd* tracep);

void Vsample_ntt_tb___024root__trace_init_top(Vsample_ntt_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsample_ntt_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsample_ntt_tb___024root*>(voidSelf);
    Vsample_ntt_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vsample_ntt_tb___024root__trace_decl_types(tracep);
    Vsample_ntt_tb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsample_ntt_tb___024root__trace_register(Vsample_ntt_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsample_ntt_tb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsample_ntt_tb::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsample_ntt_tb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
