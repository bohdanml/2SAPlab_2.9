#include "pch.h"
#include "CppUnitTest.h"
#include "../2SAPlab_2.9/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
        {
            Node* root = nullptr;
            insertNode(root, 5, 'a');
            insertNode(root, 3, 'b');
            insertNode(root, 8, 'c');

            Assert::AreEqual(root->mainData, 5);
            Assert::AreEqual(root->auxiliaryData, 'a');
            Assert::AreEqual(root->left->mainData, 3);
            Assert::AreEqual(root->left->auxiliaryData, 'b');
            Assert::AreEqual(root->right->mainData, 8);
            Assert::AreEqual(root->right->auxiliaryData, 'c');
        }
	};
}
