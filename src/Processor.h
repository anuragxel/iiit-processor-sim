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
#ifndef PROCESSOR_H
#define PROCESSOR_H

#define _BIT ( integer , position ) (( integer >> position) & 1)
#define _isSET ( integer , position ) _BIT ( integer , position ) == 1
#define CORRUPT_BIT_SET 1
#define INVALID_STREAM 2
#define FILE_NOT_READABLE 407 //File not found or Permission denied. => 404 | 403 => 407. (Not to be confused with proxy auth fail.)
#define RESET_ADDRESS 0

#include "Accumulator.h"
#include "ALU.h"
#include "Databus.h"
#include "Decoder.h"
#include "Flag.h"
#include "Instruction.h"
#include "IORF.h"
#include "MainMemory.h"
#include "MemoryAddress.h"
#include "Microinstruction.h"
#include "MicroprogramSequencer.h"
#include "Operand.h"
#include "ProgramCounter.h"
#include "RegisterArray.h"
#include "ROM.h"
#include "StackPointer.h"

#include <iostream> // TODO : Remove Later

extern Accumulator *accumulator;
extern ALU *alu;
extern Databus *databus;
extern Decoder *decoder;
extern Flag *flag;
extern Instruction *instruction;
extern IO_RF *io;
extern MainMemory *mainMemory;
extern MemoryAddress *memoryAddress;
extern Microinstruction *microinstruction;
extern MicroprogramSequencer *microprogramSequencer;
extern Operand *operand;
extern ProgramCounter *programCounter;
extern RegisterArray *registerArray;
extern ROM *rom;
extern StackPointer *stackPointer;

#endif
