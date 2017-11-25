

C_SRCS += ./DEVICE/src/soc.c \
          ./DEVICE/src/clock.c \
		  ./DEVICE/src/easyarm_flexspi_nor_config.c


./src/%.o: ./src/%.c
	$(CROSS_COMPILE)gcc $(CROSS_FLG) $(INCLUDE_PATH) -o "$@" "$<"

