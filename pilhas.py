class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            print("A pilha está vazia.")
            return None

    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        else:
            print("A pilha está vazia.")
            return None

    def size(self):
        return len(self.items)


stack = Stack()
print("A pilha está vazia?", stack.is_empty())

stack.push(1)
stack.push(2)
stack.push(3)

print("Elemento no topo da pilha:", stack.peek())

print("Removendo elemento do topo da pilha:", stack.pop())
print("Elemento no topo da pilha agora:", stack.peek())

print("Tamanho da pilha:", stack.size())
