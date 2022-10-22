################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
F2802x_GlobalVariableDefs.obj: C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/source/F2802x_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/William/workspace_v12/SPWM_LAUNCHXL-F28027" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/include" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=_LAUNCHXL-F28027 --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/William/workspace_v12/SPWM_LAUNCHXL-F28027" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/include" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=_LAUNCHXL-F28027 --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_codestartbranch.obj: C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_codestartbranch.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/William/workspace_v12/SPWM_LAUNCHXL-F28027" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/include" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=_LAUNCHXL-F28027 --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_cputimers.obj: C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_cputimers.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/William/workspace_v12/SPWM_LAUNCHXL-F28027" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/include" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=_LAUNCHXL-F28027 --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_defaultisr.obj: C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_defaultisr.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/William/workspace_v12/SPWM_LAUNCHXL-F28027" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/include" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=_LAUNCHXL-F28027 --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_gpio.obj: C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_gpio.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/William/workspace_v12/SPWM_LAUNCHXL-F28027" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/include" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=_LAUNCHXL-F28027 --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_piectrl.obj: C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_piectrl.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/William/workspace_v12/SPWM_LAUNCHXL-F28027" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/include" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=_LAUNCHXL-F28027 --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_pievect.obj: C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_pievect.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/William/workspace_v12/SPWM_LAUNCHXL-F28027" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/include" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=_LAUNCHXL-F28027 --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_sysctrl.obj: C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_sysctrl.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/William/workspace_v12/SPWM_LAUNCHXL-F28027" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/include" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=_LAUNCHXL-F28027 --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_usdelay.obj: C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_usdelay.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/William/workspace_v12/SPWM_LAUNCHXL-F28027" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/include" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=_LAUNCHXL-F28027 --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


