#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/SuiTong-PIC299-XXX.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/SuiTong-PIC299-XXX.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/APP_LED.c src/APP_Pout.c src/APP_AD.c src/APP_SAVE.c src/APP_Interrupt.c src/APP_LCD_Display.c src/APP_CAN_Send.c src/APP_CAN2_Receive.c src/APP_CAN1_Receive.c src/APP_main.c src/APP_System.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/APP_LED.o ${OBJECTDIR}/src/APP_Pout.o ${OBJECTDIR}/src/APP_AD.o ${OBJECTDIR}/src/APP_SAVE.o ${OBJECTDIR}/src/APP_Interrupt.o ${OBJECTDIR}/src/APP_LCD_Display.o ${OBJECTDIR}/src/APP_CAN_Send.o ${OBJECTDIR}/src/APP_CAN2_Receive.o ${OBJECTDIR}/src/APP_CAN1_Receive.o ${OBJECTDIR}/src/APP_main.o ${OBJECTDIR}/src/APP_System.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/APP_LED.o.d ${OBJECTDIR}/src/APP_Pout.o.d ${OBJECTDIR}/src/APP_AD.o.d ${OBJECTDIR}/src/APP_SAVE.o.d ${OBJECTDIR}/src/APP_Interrupt.o.d ${OBJECTDIR}/src/APP_LCD_Display.o.d ${OBJECTDIR}/src/APP_CAN_Send.o.d ${OBJECTDIR}/src/APP_CAN2_Receive.o.d ${OBJECTDIR}/src/APP_CAN1_Receive.o.d ${OBJECTDIR}/src/APP_main.o.d ${OBJECTDIR}/src/APP_System.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/APP_LED.o ${OBJECTDIR}/src/APP_Pout.o ${OBJECTDIR}/src/APP_AD.o ${OBJECTDIR}/src/APP_SAVE.o ${OBJECTDIR}/src/APP_Interrupt.o ${OBJECTDIR}/src/APP_LCD_Display.o ${OBJECTDIR}/src/APP_CAN_Send.o ${OBJECTDIR}/src/APP_CAN2_Receive.o ${OBJECTDIR}/src/APP_CAN1_Receive.o ${OBJECTDIR}/src/APP_main.o ${OBJECTDIR}/src/APP_System.o

# Source Files
SOURCEFILES=src/APP_LED.c src/APP_Pout.c src/APP_AD.c src/APP_SAVE.c src/APP_Interrupt.c src/APP_LCD_Display.c src/APP_CAN_Send.c src/APP_CAN2_Receive.c src/APP_CAN1_Receive.c src/APP_main.c src/APP_System.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/SuiTong-PIC299-XXX.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F6012A
MP_LINKER_FILE_OPTION=,--script=gld/p30F6012A-MUIC.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/APP_LED.o: src/APP_LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_LED.o.d 
	@${RM} ${OBJECTDIR}/src/APP_LED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_LED.c  -o ${OBJECTDIR}/src/APP_LED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_LED.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_LED.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_Pout.o: src/APP_Pout.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_Pout.o.d 
	@${RM} ${OBJECTDIR}/src/APP_Pout.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_Pout.c  -o ${OBJECTDIR}/src/APP_Pout.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_Pout.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_Pout.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_AD.o: src/APP_AD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_AD.o.d 
	@${RM} ${OBJECTDIR}/src/APP_AD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_AD.c  -o ${OBJECTDIR}/src/APP_AD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_AD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_AD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_SAVE.o: src/APP_SAVE.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_SAVE.o.d 
	@${RM} ${OBJECTDIR}/src/APP_SAVE.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_SAVE.c  -o ${OBJECTDIR}/src/APP_SAVE.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_SAVE.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_SAVE.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_Interrupt.o: src/APP_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/src/APP_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_Interrupt.c  -o ${OBJECTDIR}/src/APP_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_Interrupt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_LCD_Display.o: src/APP_LCD_Display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_LCD_Display.o.d 
	@${RM} ${OBJECTDIR}/src/APP_LCD_Display.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_LCD_Display.c  -o ${OBJECTDIR}/src/APP_LCD_Display.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_LCD_Display.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_LCD_Display.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_CAN_Send.o: src/APP_CAN_Send.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_CAN_Send.o.d 
	@${RM} ${OBJECTDIR}/src/APP_CAN_Send.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_CAN_Send.c  -o ${OBJECTDIR}/src/APP_CAN_Send.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_CAN_Send.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_CAN_Send.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_CAN2_Receive.o: src/APP_CAN2_Receive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_CAN2_Receive.o.d 
	@${RM} ${OBJECTDIR}/src/APP_CAN2_Receive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_CAN2_Receive.c  -o ${OBJECTDIR}/src/APP_CAN2_Receive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_CAN2_Receive.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_CAN2_Receive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_CAN1_Receive.o: src/APP_CAN1_Receive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_CAN1_Receive.o.d 
	@${RM} ${OBJECTDIR}/src/APP_CAN1_Receive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_CAN1_Receive.c  -o ${OBJECTDIR}/src/APP_CAN1_Receive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_CAN1_Receive.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_CAN1_Receive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_main.o: src/APP_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_main.o.d 
	@${RM} ${OBJECTDIR}/src/APP_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_main.c  -o ${OBJECTDIR}/src/APP_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_System.o: src/APP_System.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_System.o.d 
	@${RM} ${OBJECTDIR}/src/APP_System.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_System.c  -o ${OBJECTDIR}/src/APP_System.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_System.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_System.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/src/APP_LED.o: src/APP_LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_LED.o.d 
	@${RM} ${OBJECTDIR}/src/APP_LED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_LED.c  -o ${OBJECTDIR}/src/APP_LED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_LED.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_LED.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_Pout.o: src/APP_Pout.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_Pout.o.d 
	@${RM} ${OBJECTDIR}/src/APP_Pout.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_Pout.c  -o ${OBJECTDIR}/src/APP_Pout.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_Pout.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_Pout.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_AD.o: src/APP_AD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_AD.o.d 
	@${RM} ${OBJECTDIR}/src/APP_AD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_AD.c  -o ${OBJECTDIR}/src/APP_AD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_AD.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_AD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_SAVE.o: src/APP_SAVE.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_SAVE.o.d 
	@${RM} ${OBJECTDIR}/src/APP_SAVE.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_SAVE.c  -o ${OBJECTDIR}/src/APP_SAVE.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_SAVE.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_SAVE.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_Interrupt.o: src/APP_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/src/APP_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_Interrupt.c  -o ${OBJECTDIR}/src/APP_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_Interrupt.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_LCD_Display.o: src/APP_LCD_Display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_LCD_Display.o.d 
	@${RM} ${OBJECTDIR}/src/APP_LCD_Display.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_LCD_Display.c  -o ${OBJECTDIR}/src/APP_LCD_Display.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_LCD_Display.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_LCD_Display.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_CAN_Send.o: src/APP_CAN_Send.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_CAN_Send.o.d 
	@${RM} ${OBJECTDIR}/src/APP_CAN_Send.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_CAN_Send.c  -o ${OBJECTDIR}/src/APP_CAN_Send.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_CAN_Send.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_CAN_Send.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_CAN2_Receive.o: src/APP_CAN2_Receive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_CAN2_Receive.o.d 
	@${RM} ${OBJECTDIR}/src/APP_CAN2_Receive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_CAN2_Receive.c  -o ${OBJECTDIR}/src/APP_CAN2_Receive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_CAN2_Receive.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_CAN2_Receive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_CAN1_Receive.o: src/APP_CAN1_Receive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_CAN1_Receive.o.d 
	@${RM} ${OBJECTDIR}/src/APP_CAN1_Receive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_CAN1_Receive.c  -o ${OBJECTDIR}/src/APP_CAN1_Receive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_CAN1_Receive.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_CAN1_Receive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_main.o: src/APP_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_main.o.d 
	@${RM} ${OBJECTDIR}/src/APP_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_main.c  -o ${OBJECTDIR}/src/APP_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/APP_System.o: src/APP_System.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/APP_System.o.d 
	@${RM} ${OBJECTDIR}/src/APP_System.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/APP_System.c  -o ${OBJECTDIR}/src/APP_System.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/APP_System.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -O0 -I"lib" -I"src" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/APP_System.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/SuiTong-PIC299-XXX.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  lib/Pic299Base-V1.00.a  gld/p30F6012A-MUIC.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/SuiTong-PIC299-XXX.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    lib\Pic299Base-V1.00.a  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x84F   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/SuiTong-PIC299-XXX.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  lib/Pic299Base-V1.00.a gld/p30F6012A-MUIC.gld ds30/ds30.X.production.hex
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/SuiTong-PIC299-XXX.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    lib\Pic299Base-V1.00.a  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/SuiTong-PIC299-XXX.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
	@echo "Creating unified hex file"
	@"C:/Program Files (x86)/Microchip/MPLABX/v3.35/mplab_ide/mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files (x86)/Microchip/MPLABX/v3.35/mplab_ide/mplab_ide/modules/../../dat/en_msgs.txt" dist/${CND_CONF}/${IMAGE_TYPE}/SuiTong-PIC299-XXX.${IMAGE_TYPE}.hex ds30/ds30.X.production.hex -odist/${CND_CONF}/production/SuiTong-PIC299-XXX.production.unified.hex

endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
