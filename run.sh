BUILDDIR="./build"
INCLUDEDIR="./include"
PROJNAME="tetris"
mkdir -p ${BUILDDIR}
g++ -I${INCLUDEDIR} -I./ main.cpp grid.cpp color.cpp position.cpp block.cpp blocks.cpp game.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ${BUILDDIR}/${PROJNAME}
if [[ $? -eq 0 ]]; then
    ${BUILDDIR}/${PROJNAME}
else
    echo "Compilation failed."
fi
