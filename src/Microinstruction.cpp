#ifndef _MICROINSTRUCTION_CPP
#define _MICROINSTRUCTION_CPP

#include "include/Microinstruction.h"
#include "include/Processor.h"

Microinstruction::Microinstruction () {
	this->RD = false;
	this->WR = false;
	this->LMR = false;
	this->EPC = false;
	this->IPC = false;
	this->LPC = false;
	this->ESP = false;
	this->ISP = false;
	this->DSP = false;
	this->LSP = false;
	this->LIR = false;
	this->LMS = false;
	this->RMS = false;
	this->EFL = false;
	this->LIO = false;
	this->LRG = false;
	this->ERG = false;
	this->LAR = false;
	this->RAR = false;
	this->EAR = false;
	this->SAF = 0;
	this->LOR = false;
	this->ROR = false;
	this->EOR = false;
}

Microinstruction::~Microinstruction() {

}

void Microinstruction::setContent(Microinstruction content) {
	this->RD = content.RD;
	this->WR = content.WR;
	this->LMR = content.LMR;
	this->EPC = content.EPC;
	this->IPC = content.IPC;
	this->LPC = content.LPC;
	this->ESP = content.ESP;
	this->ISP = content.ISP;
	this->DSP = content.DSP;
	this->LSP = content.LSP;
	this->LIR = content.LIR;
	this->LMS = content.LMS;
	this->RMS = content.RMS;
	this->EFL = content.EFL;
	this->LIO = content.LIO;
	this->LRG = content.LRG;
	this->ERG = content.ERG;
	this->LAR = content.LAR;
	this->RAR = content.RAR;
	this->EAR = content.EAR;
	this->SAF = content.SAF;
	this->LOR = content.LOR;
	this->ROR = content.ROR;
	this->EOR = content.EOR;
}

void Microinstruction::resetContent() {
	this->RD = true;
	this->WR = false;
	this->LMR = false;
	this->EPC = false;
	this->IPC = true;
	this->LPC = false;
	this->ESP = false;
	this->ISP = false;
	this->DSP = false;
	this->LSP = false;
	this->LIR = true;
	this->LMS = true;
	this->RMS = false;
	this->EFL = false;
	this->LIO = true;
	this->LRG = false;
	this->ERG = false;
	this->LAR = false;
	this->RAR = false;
	this->EAR = false;
	this->SAF = 0;
	this->LOR = false;
	this->ROR = false;
	this->EOR = false;
}

#endif
