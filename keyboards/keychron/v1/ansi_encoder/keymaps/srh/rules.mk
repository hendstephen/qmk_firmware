ENCODER_MAP_ENABLE = no
VIA_ENABLE = yes
TAP_DANCE_ENABLE = no
DEFERRED_EXEC_ENABLE = no
DYNAMIC_TAPPING_TERM_ENABLE = no

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += rgb_matrix_user.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tapdance_user.c
endif