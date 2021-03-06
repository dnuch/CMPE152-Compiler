#
# Makefile for Chapter 12
#
# Copyright (c) 2017 by Ronald Mak
# For instructional purposes only.  No warranties.
#
TARGET = Chapter12cpp
SRCS =  Pascal.cpp \
        wci/backend/Backend.cpp \
        wci/backend/BackendFactory.cpp \
        wci/backend/compiler/CodeGenerator.cpp \
        wci/backend/interpreter/Executor.cpp \
        wci/backend/interpreter/MemoryFactory.cpp \
        wci/backend/interpreter/RuntimeError.cpp \
        wci/backend/interpreter/RuntimeErrorHandler.cpp \
        wci/backend/interpreter/executors/AssignmentExecutor.cpp \
        wci/backend/interpreter/executors/CallDeclaredExecutor.cpp \
        wci/backend/interpreter/executors/CallExecutor.cpp \
        wci/backend/interpreter/executors/CallStandardExecutor.cpp \
        wci/backend/interpreter/executors/CompoundExecutor.cpp \
        wci/backend/interpreter/executors/ExpressionExecutor.cpp \
        wci/backend/interpreter/executors/IfExecutor.cpp \
        wci/backend/interpreter/executors/LoopExecutor.cpp \
        wci/backend/interpreter/executors/SelectExecutor.cpp \
        wci/backend/interpreter/executors/StatementExecutor.cpp \
        wci/backend/interpreter/memoryimpl/ActivationRecordImpl.cpp \
        wci/backend/interpreter/memoryimpl/CellImpl.cpp \
        wci/backend/interpreter/memoryimpl/MemoryMapImpl.cpp \
        wci/backend/interpreter/memoryimpl/RuntimeDisplayImpl.cpp \
        wci/backend/interpreter/memoryimpl/RuntimeStackImpl.cpp \
        wci/frontend/FrontendFactory.cpp \
        wci/frontend/Parser.cpp \
        wci/frontend/Scanner.cpp \
        wci/frontend/Source.cpp \
        wci/frontend/Token.cpp \
        wci/frontend/pascal/PascalError.cpp \
        wci/frontend/pascal/PascalErrorHandler.cpp \
        wci/frontend/pascal/PascalParserTD.cpp \
        wci/frontend/pascal/PascalScanner.cpp \
        wci/frontend/pascal/PascalToken.cpp \
        wci/frontend/pascal/parsers/ArrayTypeParser.cpp \
        wci/frontend/pascal/parsers/AssignmentStatementParser.cpp \
        wci/frontend/pascal/parsers/BlockParser.cpp \
        wci/frontend/pascal/parsers/CallDeclaredParser.cpp \
        wci/frontend/pascal/parsers/CallParser.cpp \
        wci/frontend/pascal/parsers/CallStandardParser.cpp \
        wci/frontend/pascal/parsers/CaseStatementParser.cpp \
        wci/frontend/pascal/parsers/CompoundStatementParser.cpp \
        wci/frontend/pascal/parsers/ConstantDefinitionsParser.cpp \
        wci/frontend/pascal/parsers/DeclarationsParser.cpp \
        wci/frontend/pascal/parsers/DeclaredRoutineParser.cpp \
        wci/frontend/pascal/parsers/EnumerationTypeParser.cpp \
        wci/frontend/pascal/parsers/ExpressionParser.cpp \
        wci/frontend/pascal/parsers/ForStatementParser.cpp \
        wci/frontend/pascal/parsers/IfStatementParser.cpp \
        wci/frontend/pascal/parsers/ProgramParser.cpp \
        wci/frontend/pascal/parsers/RecordTypeParser.cpp \
        wci/frontend/pascal/parsers/RepeatStatementParser.cpp \
        wci/frontend/pascal/parsers/SimpleTypeParser.cpp \
        wci/frontend/pascal/parsers/StatementParser.cpp \
        wci/frontend/pascal/parsers/SubrangeTypeParser.cpp \
        wci/frontend/pascal/parsers/TypeDefinitionsParser.cpp \
        wci/frontend/pascal/parsers/TypeSpecificationParser.cpp \
        wci/frontend/pascal/parsers/VariableDeclarationsParser.cpp \
        wci/frontend/pascal/parsers/VariableParser.cpp \
        wci/frontend/pascal/parsers/WhileStatementParser.cpp \
        wci/frontend/pascal/tokens/PascalErrorToken.cpp \
        wci/frontend/pascal/tokens/PascalNumberToken.cpp \
        wci/frontend/pascal/tokens/PascalSpecialSymbolToken.cpp \
        wci/frontend/pascal/tokens/PascalStringToken.cpp \
        wci/frontend/pascal/tokens/PascalWordToken.cpp \
        wci/intermediate/ICodeFactory.cpp \
        wci/intermediate/SymTabFactory.cpp \
        wci/intermediate/TypeFactory.cpp \
        wci/intermediate/icodeimpl/ICodeImpl.cpp \
        wci/intermediate/icodeimpl/ICodeNodeImpl.cpp \
        wci/intermediate/symtabimpl/Predefined.cpp \
        wci/intermediate/symtabimpl/SymTabEntryImpl.cpp \
        wci/intermediate/symtabimpl/SymTabImpl.cpp \
        wci/intermediate/symtabimpl/SymTabStackImpl.cpp \
        wci/intermediate/typeimpl/TypeChecker.cpp \
        wci/intermediate/typeimpl/TypeSpecImpl.cpp \
        wci/message/Message.cpp \
        wci/message/MessageHandler.cpp \
        wci/util/CrossReferencer.cpp \
        wci/util/ParseTreePrinter.cpp
OBJS = $(SRCS:.cpp=.o)
CC = g++
CFLAGS = -std=c++0x -O0 -g3 -Wall
PFLAGS = -ix
DEP = depends
RAW_DEPENDENCY_FILE = .temp_dependencies.txt
DEPENDENCY_FILE = makefile_dependencies.txt

.cpp.o :
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(TARGET)

clean:
	rm $(OBJS) $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# Compile Pascal program hello.pas: make compile src=hello.pas
compile: $(TARGET)
	./$(TARGET) compile $(PFLAGS) $(src)

# Execute a Pascal program hello.pas: make execute src=hello.pas
execute: $(TARGET)
	./$(TARGET) execute $(PFLAGS) $(src)

# Generate dependencies on the header files.
# You shouldn't run this.
dependencies:
	$(CC) -MM $(SRCS) > $(RAW_DEPENDENCY_FILE)
	$(DEP) < $(RAW_DEPENDENCY_FILE) > $(DEPENDENCY_FILE)
	rm $(RAW_DEPENDENCY_FILE)

sinclude $(DEPENDENCY_FILE)
