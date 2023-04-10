class BST:
    def __init__(self,key):
        self.key = key
        self.lchild = None
        self.rchild = None
        
    def insert(self,data):
        if self.key is None:
            self.key = data
            return
        if (data<self.key) :
            if self.lchild :
                self.lchild.insert(data)
            else:
                self.lchild = BST(data)
        else:
            if self.rchild :
                self.rchild.insert(data)
            else:
                self.rchild = BST(data)
            

    def search(self,data):
        if self.key == data:
            print("present")
            return
        if data < self.key:
            if self.lchild:
                self.lchild.search(data)
            else:
                print("absent")
        else:
            if self.rchild:
                self.rchild.search(data)
            else:
                print("absent")

    def preorder(self):
        print(self.key)
        if self.lchild:
            self.lchild.preorder()
        if self.rchild:
            self.rchild.preorder()
        
    def inorder(self):
        if self.lchild:
            self.lchild.inorder()
        print(self.key)
        if self.rchild:
            self.rchild.inorder()
        
    def postorder(self):
        if self.lchild:
            self.lchild.inorder()
        if self.rchild:
            self.rchild.inorder()
        print(self.key)


    def delete(self,data):
        if not self.key:
            print("empty tree")
            return
        if data < self.key:
            if self.lchild:
                self.lchild=self.lchild.delete(data)
            else:
                print("not present")
        elif data > self.key:
            if self.rchild:
                self.rchild=self.rchild.delete(data)
            else:
                print("not present")
        else:
            if not self.lchild :
                temp = self.rchild
                self = None
                return temp
            if not self.rchild :
                temp = self.lchild
                self = None
                return temp
            node = self.rchild
            while node.lchild :
                node = node.lchild
            self.key = node.key
            self.rchild = self.rchild.delete(node.key)
        return self
    
    def maxNode(self):
        node=self
        while node.rchild:
            node= node.rchild
        print("maxval is ", node.key)
        

    def minNode(self):
        node=self
        while node.lchild:
            node= node.lchild
        print("minval is ", node.key)


a1=BST(7)
a1.insert(5)
a1.insert(4)
a1.insert(6)
a1.insert(20)
a1.insert(9)
a1.insert(3)
a1.maxNode()
a1.minNode()
a1.delete(20)
a1.preorder()