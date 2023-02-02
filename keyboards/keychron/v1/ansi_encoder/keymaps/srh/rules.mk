ENCODER_MAP_ENABLE = yes
VIA_ENABLE = yes
TAP_DANCE_ENABLE = yes

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += rgb_matrix_user.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tapdance_user.c
endif