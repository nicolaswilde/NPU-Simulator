DDR = ./ddr

INCLUDE_FLAG = -I./NPU_toy/ -I$(DDR)

toy:
	gcc ./NPU_toy/NPU_toy.cpp $(DDR)/*.cpp $(INCLUDE_FLAG) -o npu -g

clean:
	rm -f npu
