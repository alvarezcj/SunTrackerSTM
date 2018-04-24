/*
 * SDDriver.cpp
 *
 *  Created on: 22 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#include <utility/SDDriver.h>

SDDriver::SDDriver() {
	/* Mount FATFS on SDRAM */
	m_fres = f_mkfs("", 0, 0, m_SD_Buffer, sizeof(m_SD_Buffer));
	m_fres = f_mount(&m_fs, "", 1);

	/* Create FAT volume with default cluster size, IMPORTANT for SDRAM because content is not stored forever! */
	/* This has to be done only once, when you first time init your SDRAM */
	/* It is initialized first time using f_mount() function call above */

	/* Open file */
	m_fres = f_open(&m_fil, "SDRAM:test.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);

	/* Write data */
	m_fres = f_write(&m_fil, "Hello world", 11, NULL);

	/* Close file */
	m_fres = f_close(&m_fil);

	/* Unmount */
	f_mount(NULL, "SDRAM:", 1);

}

SDDriver::~SDDriver() {
	// TODO Auto-generated destructor stub
}

