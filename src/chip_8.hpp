#ifndef __CHIP_8_HPP__
#define __CHIP_8_HPP__

#include <cstdint>

#define MEMORY_SIZE 4096
#define REGISTER_SIZE 1
#define INDEX_REGISTER_SIZE 2
#define STACK_SIZE 64
#define POINTER_SIZE 1
#define PROGRAM_COUNTER_SIZE 2
#define FONT_SET_SIZE 0x80

#define FONT_SET_START 0
#define PROGRAM_START 0x200


class Chip8 {
    uint8_t memory[4096];
};

#endif /* __CHIP_8_HPP__ */
