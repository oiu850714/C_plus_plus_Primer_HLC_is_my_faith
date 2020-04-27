MainObj = main.o

SourcePath = src

Blob = $(SourcePath)/Blob.h
BlobPtr = $(SourcePath)/BlobPtr.h
Screen = $(SourcePath)/Screen.h
Vec = $(SourcePath)/Vec.h
DebugDelete = $(SourcePath)/DebugDelete.h

TemplatesHeader = $(Blob) $(BlobPtr) $(Screen) $(Vec) $(DebugDelete)

Utils = $(SourcePath)/some_utils.h

ObjFiles = TextQuery.o

MainFile = test.cpp

IncludePath = ./

CC = g++-8 -std=c++2a -g -fno-elide-constructors

main: $(MainObj) $(TemplatesHeader) $(Utils) $(ObjFiles)
	$(CC) -o main -I $(IncludePath) $(MainObj) $(ObjFiles)

main.o: $(MainFile) $(Utils)
	$(CC) -c -I $(IncludePath) $(MainFile) -o main.o

TextQuery.o: $(SourcePath)/TextQuery.cpp $(SourcePath)/TextQuery.h $(DebugDelete)
	$(CC) -c -I $(IncludePath) $(SourcePath)/TextQuery.cpp -o TextQuery.o

clean:
	rm -rf *.o *.out
