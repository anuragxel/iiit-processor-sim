/*
 * This file is part of Std-Arch-Sim.
 *
 * Std-Arch-Sim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Std-Arch-Sim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Std-Arch-Sim.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _ROM_CPP
#define _ROM_CPP

#include "ROM.h"
#include "Processor.h"

ROM::ROM () {
	this->hashTable.resize(61); // Will call the constructor for default values of <Microinstruction> which happens to be completly 0'd out;

	this->hashTable[0].EPC = true; 
	this->hashTable[0].LMR = true;
	this->hashTable[0].IPC = true;

	this->hashTable[1].RD = true;
	this->hashTable[1].LIR = true;
	this->hashTable[1].LMS = true;
	this->hashTable[1].LIO = true;

	// @Ghosh : nop

	this->hashTable[2].RMS = true;

	// @Ghosh : stop 
	// @Ghosh : |->	Nothing to do!

	// @Ghosh : adi xx

	this->hashTable[3].EPC = true;
	this->hashTable[3].LMR = true;
	this->hashTable[3].IPC = true;

	this->hashTable[4].RD = true;
	this->hashTable[4].LOR = true;

	this->hashTable[5].EAR = true;
	this->hashTable[5].LAR = true;
	this->hashTable[5].SAF = 0x01; // ADD
	this->hashTable[5].RMS = true;

	// @Ghosh : sbi xx

	this->hashTable[5].EPC = true;
	this->hashTable[5].LMR = true;
	this->hashTable[5].IPC = true;

	this->hashTable[6].RD = true;
	this->hashTable[6].LOR = true;

	this->hashTable[7].EAR = true;
	this->hashTable[7].LAR = true;
	this->hashTable[7].SAF = 0x02; // SUB
	this->hashTable[7].RMS = true;

	// @Ghosh : xri xx

	this->hashTable[8].EPC = true;
	this->hashTable[8].LMR = true;
	this->hashTable[8].IPC = true;

	this->hashTable[9].RD = true;
	this->hashTable[9].LOR = true;

	this->hashTable[10].EAR = true;
	this->hashTable[10].LAR = true;
	this->hashTable[10].SAF = 0x03; // XOR
	this->hashTable[10].RMS = true;

	// @Ghosh : ani xx

	this->hashTable[11].EPC = true;
	this->hashTable[11].LMR = true;
	this->hashTable[11].IPC = true;

	this->hashTable[12].RD = true;
	this->hashTable[12].LOR = true;

	this->hashTable[13].EAR = true;
	this->hashTable[13].LAR = true;
	this->hashTable[13].SAF = 0x04; // AND
	this->hashTable[13].RMS = true;

	// @Ghosh : ori xx

	this->hashTable[14].EPC = true;
	this->hashTable[14].LMR = true;
	this->hashTable[14].IPC = true;

	this->hashTable[15].RD = true;
	this->hashTable[15].LOR = true;

	this->hashTable[15].EAR = true;
	this->hashTable[15].LAR = true;
	this->hashTable[15].SAF = 0x05; // OR
	this->hashTable[15].RMS = true;

	// @Ghosh : cmi xx

	this->hashTable[16].EPC = true;
	this->hashTable[16].LMR = true;
	this->hashTable[16].IPC = true;

	this->hashTable[17].RD = true;
	this->hashTable[17].LOR = true;

	this->hashTable[18].EAR = true;
	this->hashTable[18].SAF = 0x06; // CMP === SUB
	this->hashTable[18].RMS = true;

	// @Ghosh : ret <fl>
	
	this->hashTable[19].EFL = true;
	this->hashTable[19].RMS = true;

	this->hashTable[20].ESP = true;
	this->hashTable[20].LMR = true;
	this->hashTable[20].ISP = true;

	this->hashTable[21].RD = true;
	this->hashTable[21].LPC = true;
	this->hashTable[21].RMS = true;

	// @Ghosh : add <r>

	this->hashTable[22].ERG = true;
	this->hashTable[22].LOR = true;

	this->hashTable[23].EAR = true;
	this->hashTable[23].LAR = true;
	this->hashTable[23].SAF = 0x01; // ADD
	this->hashTable[23].RMS = true;

	// @Ghosh : sub <r>

	this->hashTable[24].ERG = true;
	this->hashTable[24].LOR = true;

	this->hashTable[25].EAR = true;
	this->hashTable[25].LAR = true;
	this->hashTable[25].SAF = 0x02; // SUB
	this->hashTable[25].RMS = true;

	// @Ghosh : xor <r>

	this->hashTable[26].ERG = true;
	this->hashTable[26].LOR = true;

	this->hashTable[27].EAR = true;
	this->hashTable[27].LAR = true;
	this->hashTable[27].SAF = 0x03; // XOR
	this->hashTable[27].RMS = true;

	// @Ghosh : and <r>

	this->hashTable[28].ERG = true;
	this->hashTable[28].LOR = true;

	this->hashTable[29].EAR = true;
	this->hashTable[29].LAR = true;
	this->hashTable[29].SAF = 0x04; // AND
	this->hashTable[29].RMS = true;

	// @Ghosh : or <r>

	this->hashTable[30].ERG = true;
	this->hashTable[30].LOR = true;

	this->hashTable[31].EAR = true;
	this->hashTable[31].LAR = true;
	this->hashTable[31].SAF = 0x05; // OR
	this->hashTable[31].RMS = true;

	// @Ghosh : cmp <r>

	this->hashTable[32].ERG = true;
	this->hashTable[32].LOR = true;

	this->hashTable[33].EAR = true;
	this->hashTable[33].LAR = true;
	this->hashTable[33].SAF = 0x06; // CMP
	this->hashTable[33].RMS = true;

	// @Ghosh : movs <r>

	this->hashTable[34].ERG = true;
	this->hashTable[34].LAR = true;
	this->hashTable[34].SAF = 0x0F; //PASSO
	this->hashTable[34].RMS = true;

	// @Ghosh : movd <r>

	this->hashTable[35].EAR = true;
	this->hashTable[35].LRG = true;
	this->hashTable[35].RMS = true;

	// @Ghosh : movi <r> xx

	this->hashTable[36].EPC = true;
	this->hashTable[36].LMR = true;
	this->hashTable[36].IPC = true;

	this->hashTable[37].RD = true;
	this->hashTable[37].LRG = true;
	this->hashTable[37].RMS = true;

	// @Ghosh : stor <r> 

	this->hashTable[38].EAR = true;
	this->hashTable[38].LMR = true;

	this->hashTable[39].ERG = true;
	this->hashTable[39].WR = true;
	this->hashTable[39].RMS = true;

	// @Ghosh : load <r>

	this->hashTable[40].EAR = true;
	this->hashTable[40].LMR = true;

	this->hashTable[41].RD = true;
	this->hashTable[41].LRG = true;
	this->hashTable[41].RMS = true;

	// @Ghosh : push <r>

	this->hashTable[42].DSP = true;

	this->hashTable[43].ESP = true;
	this->hashTable[43].LMR = true;

	this->hashTable[44].ERG = true;
	this->hashTable[44].WR = true;
	this->hashTable[44].RMS = true;

	// @Ghosh : pop <r>

	this->hashTable[45].ESP = true;
	this->hashTable[45].LMR = true;
	this->hashTable[45].ISP = true;

	this->hashTable[46].RD = true;
	this->hashTable[46].LRG = true;
	this->hashTable[46].RMS = true;

	// @Ghosh : jumpd <fl> xx

	this->hashTable[47].EPC = true;
	this->hashTable[47].LMR = true;
	this->hashTable[47].IPC = true;
	this->hashTable[47].EFL = true;
	this->hashTable[47].RMS = true;

	this->hashTable[48].RD = true;
	this->hashTable[48].LPC = true;
	this->hashTable[48].RMS = true;

	// @Ghosh : jmpr <fl>

	this->hashTable[49].EFL = true;
	this->hashTable[49].RMS = true;

	this->hashTable[50].EAR = true;
	this->hashTable[50].LPC = true;
	this->hashTable[50].RMS = true;

	// @Ghosh : cd <fl> xx

	this->hashTable[51].EPC = true;
	this->hashTable[51].LMR = true;
	this->hashTable[51].IPC = true;
	this->hashTable[51].EFL = true;
	this->hashTable[51].RMS = true;

	this->hashTable[52].RD = true;
	this->hashTable[52].LOR = true;
	this->hashTable[52].DSP = true;

	this->hashTable[53].ESP = true;
	this->hashTable[53].LMR = true;

	this->hashTable[54].EPC = true;
	this->hashTable[54].WR = true;

	this->hashTable[55].EOR = true;
	this->hashTable[55].LPC = true;
	this->hashTable[55].RMS = true;

	// @Ghosh : cr <fl> 

	this->hashTable[56].EFL = true;
	this->hashTable[56].RMS = true;

	this->hashTable[57].DSP = true;

	this->hashTable[58].ESP = true;
	this->hashTable[58].LMR = true;

	this->hashTable[59].EPC = true;
	this->hashTable[59].WR = true;

	this->hashTable[60].EAR = true;
	this->hashTable[60].LPC = true;
	this->hashTable[60].RMS = true;
}

ROM::~ROM () {
	this->hashTable.clear();
}

void ROM::setMicroinstruction () {
	microinstruction->setContent(this->hashTable[ microprogramSequencer->getContent() ]);
}

ROM::ROM (std::string path) {

}

ROM::ROM (std::fstream infile) {

}

ROM::ROM (std::ifstream infile) {

}

#endif
