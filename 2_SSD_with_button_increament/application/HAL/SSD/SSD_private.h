/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SSD_private file >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * @author : Ahmed Khaled Abdelmaksod Ebrahim
 * @layer  : HAL
 * @brief  : contains things related to Seven segment device HW
 */

#ifndef _SSD_PRIVATE_H_
#define _SSD_PRIVATE_H_

#define SSD_COMMON_CATHOD_ARRAY  {0xBF, 0x06, 0x5B, 0xCF, 0xE6, 0xED, 0xFC, 0x07, 0xFF, 0xE7}
#define SSD_COMMON_ANODE_ARRAY   {0x40, 0xF9, 0xA4, 0x30, 0x19, 0x12, 0x03, 0xF8, 0x00, 0x18}

#endif

//  0x49 // 0b 0100 1001
//    001 0010 -> 1110 1101 -> ed
// 0 -> 0x0100 0000 -> 0x1011 1111
// 1 -> F9 -> 1111 1001 -> 0000 0110
// 2 -> A4 -> 1010 0100 -> 0101 1011
// 3 -> 30 -> 0011 0000 -> 1100 1111
// 4 -> 19 -> 0001 1001 -> 1110 0110
// 6 -> 03 -> 0000 0011 -> 1111 1100
// 7 -> F8 -> 1111 1000 -> 0000 0111
// 8 -> 00 -> 0000 0000 -> 1111 1111
// 9 -> 18 -> 0001 1000 -> 1110 0111
