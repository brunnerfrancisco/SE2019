#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"
#include "system.h"

int main()
{
	while (1)
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_1_BASE, IORD_ALTERA_AVALON_PIO_DATA(PIO_0_BASE));
}
