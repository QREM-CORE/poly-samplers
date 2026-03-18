// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsample_ntt_tb.h for the primary calling header

#include "Vsample_ntt_tb__pch.h"
#include "Vsample_ntt_tb__Syms.h"
#include "Vsample_ntt_tb___024root.h"

void Vsample_ntt_tb___024root___ctor_var_reset(Vsample_ntt_tb___024root* vlSelf);

Vsample_ntt_tb___024root::Vsample_ntt_tb___024root(Vsample_ntt_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsample_ntt_tb___024root___ctor_var_reset(this);
}

void Vsample_ntt_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsample_ntt_tb___024root::~Vsample_ntt_tb___024root() {
}
