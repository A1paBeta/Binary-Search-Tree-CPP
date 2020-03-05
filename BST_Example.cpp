#include "BST.h"
#include "Testing.h"

int main(void){
    Timer timer = Timer();
    BinarySearchTree bst = BinarySearchTree();

    suffleRandom();
    for(int i=0;i<10000;++i){ bst.insertNode(getRandomData()); }

    bst.showAllNode();

    cout << '\n' << "Execute time : " << timer.getNowExecuteTime() << "(sec)";

    return 0;
}
