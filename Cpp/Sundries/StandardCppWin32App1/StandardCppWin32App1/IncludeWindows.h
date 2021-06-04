#pragma once

#ifndef INCLUDEWINDOWS_H
#define INCLUDEWINDOWS_H

// Always use this header to include Windows.h.
// This ensures that you will not accidentally have inconsistent usage of macros that enable/disable parts of Windows.h (such as NOMINMAX).

// Exclude the min and max macros from Windows.h; you should use std::min and std::max instead, if necessary.
#define NOMINMAX
#include <Windows.h>

#endif
