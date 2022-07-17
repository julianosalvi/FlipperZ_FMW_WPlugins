#pragma once

#include <flipper_application/elf/elf.h>
#include <stdbool.h>

typedef struct {
    uint16_t api_version_major;
    uint16_t api_version_minor;
    bool (*resolver_callback)(const char* name, Elf32_Addr* address);
} ElfApiInterface;
