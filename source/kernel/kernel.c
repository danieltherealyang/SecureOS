#include "init.h"
#include "io.h"
#include "string.h"
#include "terminal_driver.h"
#include <stdint.h>
#include "paging.h"

void main()
{
    init_drivers();
    terminal_clear();
    terminal_update_cursor();
    string s;
    s.data = "HEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLLLLLLLLLLLLLLLLLL"
             "LLOOOOOOOOOOOOOOOOOOOOOOOOOOOOO";
    s.len = 96;
    printf(&s);
    enable_paging(0x100000);
}