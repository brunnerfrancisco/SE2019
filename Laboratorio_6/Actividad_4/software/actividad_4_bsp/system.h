/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'nios_2'
 * SOPC Builder design path: ../../nios_2.sopcinfo
 *
 * Generated: Sun Nov 03 18:21:43 ART 2019
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00040820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x13
#define ALT_CPU_DCACHE_BYPASS_MASK 0x80000000
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x00000020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x13
#define ALT_CPU_NAME "nios2_gen2_0"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00040820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x13
#define NIOS2_DCACHE_BYPASS_MASK 0x80000000
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x00000020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x13
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x41140
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x41140
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x41140
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_2"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_0
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x41140
#define JTAG_UART_0_IRQ 1
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x0
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "nios_2_onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 131072
#define ONCHIP_MEMORY2_0_SPAN 131072
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * pio_0 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_0 altera_avalon_pio
#define PIO_0_BASE 0x41130
#define PIO_0_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_0_CAPTURE 0
#define PIO_0_DATA_WIDTH 8
#define PIO_0_DO_TEST_BENCH_WIRING 0
#define PIO_0_DRIVEN_SIM_VALUE 0
#define PIO_0_EDGE_TYPE "NONE"
#define PIO_0_FREQ 50000000
#define PIO_0_HAS_IN 1
#define PIO_0_HAS_OUT 0
#define PIO_0_HAS_TRI 0
#define PIO_0_IRQ -1
#define PIO_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_0_IRQ_TYPE "NONE"
#define PIO_0_NAME "/dev/pio_0"
#define PIO_0_RESET_VALUE 0
#define PIO_0_SPAN 16
#define PIO_0_TYPE "altera_avalon_pio"


/*
 * pio_1 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_1 altera_avalon_pio
#define PIO_1_BASE 0x41120
#define PIO_1_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_1_CAPTURE 0
#define PIO_1_DATA_WIDTH 8
#define PIO_1_DO_TEST_BENCH_WIRING 0
#define PIO_1_DRIVEN_SIM_VALUE 0
#define PIO_1_EDGE_TYPE "NONE"
#define PIO_1_FREQ 50000000
#define PIO_1_HAS_IN 0
#define PIO_1_HAS_OUT 1
#define PIO_1_HAS_TRI 0
#define PIO_1_IRQ -1
#define PIO_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_1_IRQ_TYPE "NONE"
#define PIO_1_NAME "/dev/pio_1"
#define PIO_1_RESET_VALUE 0
#define PIO_1_SPAN 16
#define PIO_1_TYPE "altera_avalon_pio"


/*
 * pio_10 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_10 altera_avalon_pio
#define PIO_10_BASE 0x41020
#define PIO_10_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_10_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_10_CAPTURE 0
#define PIO_10_DATA_WIDTH 8
#define PIO_10_DO_TEST_BENCH_WIRING 0
#define PIO_10_DRIVEN_SIM_VALUE 0
#define PIO_10_EDGE_TYPE "NONE"
#define PIO_10_FREQ 50000000
#define PIO_10_HAS_IN 0
#define PIO_10_HAS_OUT 1
#define PIO_10_HAS_TRI 0
#define PIO_10_IRQ -1
#define PIO_10_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_10_IRQ_TYPE "NONE"
#define PIO_10_NAME "/dev/pio_10"
#define PIO_10_RESET_VALUE 0
#define PIO_10_SPAN 16
#define PIO_10_TYPE "altera_avalon_pio"


/*
 * pio_11 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_11 altera_avalon_pio
#define PIO_11_BASE 0x41030
#define PIO_11_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_11_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_11_CAPTURE 0
#define PIO_11_DATA_WIDTH 8
#define PIO_11_DO_TEST_BENCH_WIRING 0
#define PIO_11_DRIVEN_SIM_VALUE 0
#define PIO_11_EDGE_TYPE "NONE"
#define PIO_11_FREQ 50000000
#define PIO_11_HAS_IN 0
#define PIO_11_HAS_OUT 1
#define PIO_11_HAS_TRI 0
#define PIO_11_IRQ -1
#define PIO_11_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_11_IRQ_TYPE "NONE"
#define PIO_11_NAME "/dev/pio_11"
#define PIO_11_RESET_VALUE 0
#define PIO_11_SPAN 16
#define PIO_11_TYPE "altera_avalon_pio"


/*
 * pio_12 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_12 altera_avalon_pio
#define PIO_12_BASE 0x41040
#define PIO_12_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_12_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_12_CAPTURE 0
#define PIO_12_DATA_WIDTH 8
#define PIO_12_DO_TEST_BENCH_WIRING 0
#define PIO_12_DRIVEN_SIM_VALUE 0
#define PIO_12_EDGE_TYPE "NONE"
#define PIO_12_FREQ 50000000
#define PIO_12_HAS_IN 0
#define PIO_12_HAS_OUT 1
#define PIO_12_HAS_TRI 0
#define PIO_12_IRQ -1
#define PIO_12_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_12_IRQ_TYPE "NONE"
#define PIO_12_NAME "/dev/pio_12"
#define PIO_12_RESET_VALUE 0
#define PIO_12_SPAN 16
#define PIO_12_TYPE "altera_avalon_pio"


/*
 * pio_13 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_13 altera_avalon_pio
#define PIO_13_BASE 0x41050
#define PIO_13_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_13_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_13_CAPTURE 0
#define PIO_13_DATA_WIDTH 8
#define PIO_13_DO_TEST_BENCH_WIRING 0
#define PIO_13_DRIVEN_SIM_VALUE 0
#define PIO_13_EDGE_TYPE "NONE"
#define PIO_13_FREQ 50000000
#define PIO_13_HAS_IN 0
#define PIO_13_HAS_OUT 1
#define PIO_13_HAS_TRI 0
#define PIO_13_IRQ -1
#define PIO_13_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_13_IRQ_TYPE "NONE"
#define PIO_13_NAME "/dev/pio_13"
#define PIO_13_RESET_VALUE 0
#define PIO_13_SPAN 16
#define PIO_13_TYPE "altera_avalon_pio"


/*
 * pio_14 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_14 altera_avalon_pio
#define PIO_14_BASE 0x41060
#define PIO_14_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_14_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_14_CAPTURE 0
#define PIO_14_DATA_WIDTH 8
#define PIO_14_DO_TEST_BENCH_WIRING 0
#define PIO_14_DRIVEN_SIM_VALUE 0
#define PIO_14_EDGE_TYPE "NONE"
#define PIO_14_FREQ 50000000
#define PIO_14_HAS_IN 0
#define PIO_14_HAS_OUT 1
#define PIO_14_HAS_TRI 0
#define PIO_14_IRQ -1
#define PIO_14_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_14_IRQ_TYPE "NONE"
#define PIO_14_NAME "/dev/pio_14"
#define PIO_14_RESET_VALUE 0
#define PIO_14_SPAN 16
#define PIO_14_TYPE "altera_avalon_pio"


/*
 * pio_15 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_15 altera_avalon_pio
#define PIO_15_BASE 0x41070
#define PIO_15_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_15_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_15_CAPTURE 0
#define PIO_15_DATA_WIDTH 8
#define PIO_15_DO_TEST_BENCH_WIRING 0
#define PIO_15_DRIVEN_SIM_VALUE 0
#define PIO_15_EDGE_TYPE "NONE"
#define PIO_15_FREQ 50000000
#define PIO_15_HAS_IN 0
#define PIO_15_HAS_OUT 1
#define PIO_15_HAS_TRI 0
#define PIO_15_IRQ -1
#define PIO_15_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_15_IRQ_TYPE "NONE"
#define PIO_15_NAME "/dev/pio_15"
#define PIO_15_RESET_VALUE 0
#define PIO_15_SPAN 16
#define PIO_15_TYPE "altera_avalon_pio"


/*
 * pio_16 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_16 altera_avalon_pio
#define PIO_16_BASE 0x41080
#define PIO_16_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_16_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_16_CAPTURE 0
#define PIO_16_DATA_WIDTH 8
#define PIO_16_DO_TEST_BENCH_WIRING 0
#define PIO_16_DRIVEN_SIM_VALUE 0
#define PIO_16_EDGE_TYPE "NONE"
#define PIO_16_FREQ 50000000
#define PIO_16_HAS_IN 0
#define PIO_16_HAS_OUT 1
#define PIO_16_HAS_TRI 0
#define PIO_16_IRQ -1
#define PIO_16_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_16_IRQ_TYPE "NONE"
#define PIO_16_NAME "/dev/pio_16"
#define PIO_16_RESET_VALUE 0
#define PIO_16_SPAN 16
#define PIO_16_TYPE "altera_avalon_pio"


/*
 * pio_17 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_17 altera_avalon_pio
#define PIO_17_BASE 0x41090
#define PIO_17_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_17_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_17_CAPTURE 0
#define PIO_17_DATA_WIDTH 8
#define PIO_17_DO_TEST_BENCH_WIRING 0
#define PIO_17_DRIVEN_SIM_VALUE 0
#define PIO_17_EDGE_TYPE "NONE"
#define PIO_17_FREQ 50000000
#define PIO_17_HAS_IN 0
#define PIO_17_HAS_OUT 1
#define PIO_17_HAS_TRI 0
#define PIO_17_IRQ -1
#define PIO_17_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_17_IRQ_TYPE "NONE"
#define PIO_17_NAME "/dev/pio_17"
#define PIO_17_RESET_VALUE 0
#define PIO_17_SPAN 16
#define PIO_17_TYPE "altera_avalon_pio"


/*
 * pio_2 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_2 altera_avalon_pio
#define PIO_2_BASE 0x410a0
#define PIO_2_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_2_CAPTURE 0
#define PIO_2_DATA_WIDTH 8
#define PIO_2_DO_TEST_BENCH_WIRING 0
#define PIO_2_DRIVEN_SIM_VALUE 0
#define PIO_2_EDGE_TYPE "NONE"
#define PIO_2_FREQ 50000000
#define PIO_2_HAS_IN 1
#define PIO_2_HAS_OUT 0
#define PIO_2_HAS_TRI 0
#define PIO_2_IRQ -1
#define PIO_2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_2_IRQ_TYPE "NONE"
#define PIO_2_NAME "/dev/pio_2"
#define PIO_2_RESET_VALUE 0
#define PIO_2_SPAN 16
#define PIO_2_TYPE "altera_avalon_pio"


/*
 * pio_3 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_3 altera_avalon_pio
#define PIO_3_BASE 0x410b0
#define PIO_3_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_3_CAPTURE 0
#define PIO_3_DATA_WIDTH 8
#define PIO_3_DO_TEST_BENCH_WIRING 0
#define PIO_3_DRIVEN_SIM_VALUE 0
#define PIO_3_EDGE_TYPE "NONE"
#define PIO_3_FREQ 50000000
#define PIO_3_HAS_IN 1
#define PIO_3_HAS_OUT 0
#define PIO_3_HAS_TRI 0
#define PIO_3_IRQ -1
#define PIO_3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_3_IRQ_TYPE "NONE"
#define PIO_3_NAME "/dev/pio_3"
#define PIO_3_RESET_VALUE 0
#define PIO_3_SPAN 16
#define PIO_3_TYPE "altera_avalon_pio"


/*
 * pio_4 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_4 altera_avalon_pio
#define PIO_4_BASE 0x410c0
#define PIO_4_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_4_CAPTURE 0
#define PIO_4_DATA_WIDTH 8
#define PIO_4_DO_TEST_BENCH_WIRING 0
#define PIO_4_DRIVEN_SIM_VALUE 0
#define PIO_4_EDGE_TYPE "NONE"
#define PIO_4_FREQ 50000000
#define PIO_4_HAS_IN 1
#define PIO_4_HAS_OUT 0
#define PIO_4_HAS_TRI 0
#define PIO_4_IRQ -1
#define PIO_4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_4_IRQ_TYPE "NONE"
#define PIO_4_NAME "/dev/pio_4"
#define PIO_4_RESET_VALUE 0
#define PIO_4_SPAN 16
#define PIO_4_TYPE "altera_avalon_pio"


/*
 * pio_5 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_5 altera_avalon_pio
#define PIO_5_BASE 0x410d0
#define PIO_5_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_5_CAPTURE 0
#define PIO_5_DATA_WIDTH 8
#define PIO_5_DO_TEST_BENCH_WIRING 0
#define PIO_5_DRIVEN_SIM_VALUE 0
#define PIO_5_EDGE_TYPE "NONE"
#define PIO_5_FREQ 50000000
#define PIO_5_HAS_IN 1
#define PIO_5_HAS_OUT 0
#define PIO_5_HAS_TRI 0
#define PIO_5_IRQ -1
#define PIO_5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_5_IRQ_TYPE "NONE"
#define PIO_5_NAME "/dev/pio_5"
#define PIO_5_RESET_VALUE 0
#define PIO_5_SPAN 16
#define PIO_5_TYPE "altera_avalon_pio"


/*
 * pio_6 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_6 altera_avalon_pio
#define PIO_6_BASE 0x410e0
#define PIO_6_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_6_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_6_CAPTURE 0
#define PIO_6_DATA_WIDTH 8
#define PIO_6_DO_TEST_BENCH_WIRING 0
#define PIO_6_DRIVEN_SIM_VALUE 0
#define PIO_6_EDGE_TYPE "NONE"
#define PIO_6_FREQ 50000000
#define PIO_6_HAS_IN 1
#define PIO_6_HAS_OUT 0
#define PIO_6_HAS_TRI 0
#define PIO_6_IRQ -1
#define PIO_6_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_6_IRQ_TYPE "NONE"
#define PIO_6_NAME "/dev/pio_6"
#define PIO_6_RESET_VALUE 0
#define PIO_6_SPAN 16
#define PIO_6_TYPE "altera_avalon_pio"


/*
 * pio_7 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_7 altera_avalon_pio
#define PIO_7_BASE 0x410f0
#define PIO_7_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_7_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_7_CAPTURE 0
#define PIO_7_DATA_WIDTH 8
#define PIO_7_DO_TEST_BENCH_WIRING 0
#define PIO_7_DRIVEN_SIM_VALUE 0
#define PIO_7_EDGE_TYPE "NONE"
#define PIO_7_FREQ 50000000
#define PIO_7_HAS_IN 1
#define PIO_7_HAS_OUT 0
#define PIO_7_HAS_TRI 0
#define PIO_7_IRQ -1
#define PIO_7_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_7_IRQ_TYPE "NONE"
#define PIO_7_NAME "/dev/pio_7"
#define PIO_7_RESET_VALUE 0
#define PIO_7_SPAN 16
#define PIO_7_TYPE "altera_avalon_pio"


/*
 * pio_8 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_8 altera_avalon_pio
#define PIO_8_BASE 0x41100
#define PIO_8_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_8_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_8_CAPTURE 0
#define PIO_8_DATA_WIDTH 8
#define PIO_8_DO_TEST_BENCH_WIRING 0
#define PIO_8_DRIVEN_SIM_VALUE 0
#define PIO_8_EDGE_TYPE "NONE"
#define PIO_8_FREQ 50000000
#define PIO_8_HAS_IN 1
#define PIO_8_HAS_OUT 0
#define PIO_8_HAS_TRI 0
#define PIO_8_IRQ -1
#define PIO_8_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_8_IRQ_TYPE "NONE"
#define PIO_8_NAME "/dev/pio_8"
#define PIO_8_RESET_VALUE 0
#define PIO_8_SPAN 16
#define PIO_8_TYPE "altera_avalon_pio"


/*
 * pio_9 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_9 altera_avalon_pio
#define PIO_9_BASE 0x41110
#define PIO_9_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_9_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_9_CAPTURE 0
#define PIO_9_DATA_WIDTH 8
#define PIO_9_DO_TEST_BENCH_WIRING 0
#define PIO_9_DRIVEN_SIM_VALUE 0
#define PIO_9_EDGE_TYPE "NONE"
#define PIO_9_FREQ 50000000
#define PIO_9_HAS_IN 1
#define PIO_9_HAS_OUT 0
#define PIO_9_HAS_TRI 0
#define PIO_9_IRQ -1
#define PIO_9_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_9_IRQ_TYPE "NONE"
#define PIO_9_NAME "/dev/pio_9"
#define PIO_9_RESET_VALUE 0
#define PIO_9_SPAN 16
#define PIO_9_TYPE "altera_avalon_pio"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x41148
#define SYSID_QSYS_0_ID 0
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1572815100
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x41000
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 50000000
#define TIMER_0_IRQ 0
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 49999999
#define TIMER_0_MULT 1.0
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "s"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
