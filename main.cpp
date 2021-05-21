#include <iostream>
#include <functional>
/**
 *
 * @tparam memword Data type of one word of memory, generally equivalent to width of external data bus
 * @tparam dataword Data type of datapath. Generally an 8-bit machine will use an 8-bit data type
 */
template<typename memword=uint8_t, typename dataword=uint8_t, typename addr=uint16_t>
class CPU_6502 {
  // Syntax from https://stackoverflow.com/a/50146988/6655321
  std::function<void()> instruction_map[256] {
          /* 0x00-0x0F */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0x10-0x1F */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0x20-0x2F */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0x30-0x3F */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0x40-0x4F */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0x50-0x5F */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0x60-0x6F */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0x70-0x7F */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0x80-0x8F */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0x90-0x9F */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0xA0-0xAF */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,[&]() {
            a=fetch();
            n=(a & 0x80)?1:0;
            z=(a==0);
          },
            nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0xB0-0xBF */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0xC0-0xCF */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0xD0-0xDF */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0xE0-0xEF */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          /* 0xF0-0xFF */
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
          nullptr,nullptr,nullptr,nullptr,
  };
public:
  addr pc;
  memword a,x,y,sp;
  bool n,z,c,i,d,v;
  dataword fetch() {
    return 0xA9;
  }
  void execute() {
    instruction_map[fetch()]();
  }
  void reset() {
    pc=0xFFFC;
  }
};

int main() {
  CPU_6502 cpu;
  cpu.reset();
  cpu.execute();
}
