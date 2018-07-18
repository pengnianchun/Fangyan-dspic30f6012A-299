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
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=a
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Pic299Base.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=a
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Pic299Base.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=src/ADC.c src/CAN.c src/EEROM_asm.s src/I2C.c src/DS3231.c src/SMSTEP.c src/ALARM_LED.c src/SWITCH.c src/LCD.c src/TIMER.c src/EEROM.c src/INT.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/ADC.o ${OBJECTDIR}/src/CAN.o ${OBJECTDIR}/src/EEROM_asm.o ${OBJECTDIR}/src/I2C.o ${OBJECTDIR}/src/DS3231.o ${OBJECTDIR}/src/SMSTEP.o ${OBJECTDIR}/src/ALARM_LED.o ${OBJECTDIR}/src/SWITCH.o ${OBJECTDIR}/src/LCD.o ${OBJECTDIR}/src/TIMER.o ${OBJECTDIR}/src/EEROM.o ${OBJECTDIR}/src/INT.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/ADC.o.d ${OBJECTDIR}/src/CAN.o.d ${OBJECTDIR}/src/EEROM_asm.o.d ${OBJECTDIR}/src/I2C.o.d ${OBJECTDIR}/src/DS3231.o.d ${OBJECTDIR}/src/SMSTEP.o.d ${OBJECTDIR}/src/ALARM_LED.o.d ${OBJECTDIR}/src/SWITCH.o.d ${OBJECTDIR}/src/LCD.o.d ${OBJECTDIR}/src/TIMER.o.d ${OBJECTDIR}/src/EEROM.o.d ${OBJECTDIR}/src/INT.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/ADC.o ${OBJECTDIR}/src/CAN.o ${OBJECTDIR}/src/EEROM_asm.o ${OBJECTDIR}/src/I2C.o ${OBJECTDIR}/src/DS3231.o ${OBJECTDIR}/src/SMSTEP.o ${OBJECTDIR}/src/ALARM_LED.o ${OBJECTDIR}/src/SWITCH.o ${OBJECTDIR}/src/LCD.o ${OBJECTDIR}/src/TIMER.o ${OBJECTDIR}/src/EEROM.o ${OBJECTDIR}/src/INT.o

# Source Files
SOURCEFILES=src/ADC.c src/CAN.c src/EEROM_asm.s src/I2C.c src/DS3231.c src/SMSTEP.c src/ALARM_LED.c src/SWITCH.c src/LCD.c src/TIMER.c src/EEROM.c src/INT.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Pic299Base.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F6012A
MP_LINKER_FILE_OPTION=,--script=p30F6012A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/ADC.o: src/ADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/ADC.o.d 
	@${RM} ${OBJECTDIR}/src/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/ADC.c  -o ${OBJECTDIR}/src/ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/ADC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/ADC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/CAN.o: src/CAN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/CAN.o.d 
	@${RM} ${OBJECTDIR}/src/CAN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/CAN.c  -o ${OBJECTDIR}/src/CAN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/CAN.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/CAN.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/I2C.o: src/I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/I2C.o.d 
	@${RM} ${OBJECTDIR}/src/I2C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/I2C.c  -o ${OBJECTDIR}/src/I2C.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/I2C.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/I2C.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/DS3231.o: src/DS3231.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/DS3231.o.d 
	@${RM} ${OBJECTDIR}/src/DS3231.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/DS3231.c  -o ${OBJECTDIR}/src/DS3231.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/DS3231.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/DS3231.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/SMSTEP.o: src/SMSTEP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/SMSTEP.o.d 
	@${RM} ${OBJECTDIR}/src/SMSTEP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/SMSTEP.c  -o ${OBJECTDIR}/src/SMSTEP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/SMSTEP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/SMSTEP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/ALARM_LED.o: src/ALARM_LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/ALARM_LED.o.d 
	@${RM} ${OBJECTDIR}/src/ALARM_LED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/ALARM_LED.c  -o ${OBJECTDIR}/src/ALARM_LED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/ALARM_LED.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/ALARM_LED.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/SWITCH.o: src/SWITCH.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/SWITCH.o.d 
	@${RM} ${OBJECTDIR}/src/SWITCH.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/SWITCH.c  -o ${OBJECTDIR}/src/SWITCH.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/SWITCH.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/SWITCH.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/LCD.o: src/LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/LCD.o.d 
	@${RM} ${OBJECTDIR}/src/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/LCD.c  -o ${OBJECTDIR}/src/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/LCD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/LCD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/TIMER.o: src/TIMER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/TIMER.o.d 
	@${RM} ${OBJECTDIR}/src/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/TIMER.c  -o ${OBJECTDIR}/src/TIMER.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/TIMER.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/TIMER.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/EEROM.o: src/EEROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/EEROM.o.d 
	@${RM} ${OBJECTDIR}/src/EEROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/EEROM.c  -o ${OBJECTDIR}/src/EEROM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/EEROM.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/EEROM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/INT.o: src/INT.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/INT.o.d 
	@${RM} ${OBJECTDIR}/src/INT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/INT.c  -o ${OBJECTDIR}/src/INT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/INT.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/INT.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/src/ADC.o: src/ADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/ADC.o.d 
	@${RM} ${OBJECTDIR}/src/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/ADC.c  -o ${OBJECTDIR}/src/ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/ADC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/ADC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/CAN.o: src/CAN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/CAN.o.d 
	@${RM} ${OBJECTDIR}/src/CAN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/CAN.c  -o ${OBJECTDIR}/src/CAN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/CAN.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/CAN.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/I2C.o: src/I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/I2C.o.d 
	@${RM} ${OBJECTDIR}/src/I2C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/I2C.c  -o ${OBJECTDIR}/src/I2C.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/I2C.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/I2C.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/DS3231.o: src/DS3231.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/DS3231.o.d 
	@${RM} ${OBJECTDIR}/src/DS3231.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/DS3231.c  -o ${OBJECTDIR}/src/DS3231.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/DS3231.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/DS3231.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/SMSTEP.o: src/SMSTEP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/SMSTEP.o.d 
	@${RM} ${OBJECTDIR}/src/SMSTEP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/SMSTEP.c  -o ${OBJECTDIR}/src/SMSTEP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/SMSTEP.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/SMSTEP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/ALARM_LED.o: src/ALARM_LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/ALARM_LED.o.d 
	@${RM} ${OBJECTDIR}/src/ALARM_LED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/ALARM_LED.c  -o ${OBJECTDIR}/src/ALARM_LED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/ALARM_LED.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/ALARM_LED.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/SWITCH.o: src/SWITCH.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/SWITCH.o.d 
	@${RM} ${OBJECTDIR}/src/SWITCH.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/SWITCH.c  -o ${OBJECTDIR}/src/SWITCH.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/SWITCH.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/SWITCH.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/LCD.o: src/LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/LCD.o.d 
	@${RM} ${OBJECTDIR}/src/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/LCD.c  -o ${OBJECTDIR}/src/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/LCD.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/LCD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/TIMER.o: src/TIMER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/TIMER.o.d 
	@${RM} ${OBJECTDIR}/src/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/TIMER.c  -o ${OBJECTDIR}/src/TIMER.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/TIMER.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/TIMER.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/EEROM.o: src/EEROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/EEROM.o.d 
	@${RM} ${OBJECTDIR}/src/EEROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/EEROM.c  -o ${OBJECTDIR}/src/EEROM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/EEROM.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/EEROM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/INT.o: src/INT.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/INT.o.d 
	@${RM} ${OBJECTDIR}/src/INT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/INT.c  -o ${OBJECTDIR}/src/INT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/INT.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"../" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/src/INT.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/EEROM_asm.o: src/EEROM_asm.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/EEROM_asm.o.d 
	@${RM} ${OBJECTDIR}/src/EEROM_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  src/EEROM_asm.s  -o ${OBJECTDIR}/src/EEROM_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/src/EEROM_asm.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/src/EEROM_asm.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/src/EEROM_asm.o: src/EEROM_asm.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/EEROM_asm.o.d 
	@${RM} ${OBJECTDIR}/src/EEROM_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  src/EEROM_asm.s  -o ${OBJECTDIR}/src/EEROM_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/src/EEROM_asm.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/src/EEROM_asm.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: archive
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Pic299Base.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/Pic299Base.${OUTPUT_SUFFIX} 
	${MP_AR} $(MP_EXTRA_AR_PRE)  -omf=elf -r dist/${CND_CONF}/${IMAGE_TYPE}/Pic299Base.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Pic299Base.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/Pic299Base.${OUTPUT_SUFFIX} 
	${MP_AR} $(MP_EXTRA_AR_PRE)  -omf=elf -r dist/${CND_CONF}/${IMAGE_TYPE}/Pic299Base.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      
	
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
