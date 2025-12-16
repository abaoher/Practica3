#ifndef BSTREE_H
#define BSTREE_H

#include "BSNode.h"

template <typename T>
class BSTree {
	private:
		BSNode<T> *root;
		int nelem;
		
		BSNode<T> *search(BSNode <T> *n, T e) const {
			
			if(n == nullptr) {
				throw std::runtime_error("No se ha encontrado el elemento");
			}
			
			else if(e < n->elem){
				return search(n->left, e);
			}
			
			else if(e > n->elem) {
				return search(n->right, e);
			}
			
			else {
				return n;
			}
		}


		BSNode<T> *insert(BSNode<T> *n, T e) {
			
			if(n == nullptr) {
                                return new BSNode<T>(e);
                        }
		
			else if(e == n->elem) {
				throw std::runtime_error("El elemento ya se encuentra en el árbol");
			} 
		
			else if(e < n->elem) {
				n->left =  insert(n->left, e);
			}
			
			else if(e > n->elem) {
				n->right = insert(n->right, e);
			}	
			
			return n;
		}
		
		void print_inorder(std::ostream &out, BSNode<T> *n) const {
			
			if(n != nullptr) {
				print_inorder(out, n->left);
				out << n->elem << " ";
				print_inorder(out, n->right);
			}
			
		}
		
		T max(BSNode<T> *n) const {
			if(n == nullptr) {
				throw std::runtime_error("No hay raíz por la que empezar a buscar");
			} else if (n->right != nullptr){
				
				return max(n->right);
			} else {
				
				return n->elem;
			}
		}

		BSNode<T> *remove_max(BSNode<T> *n) {
			if(n == nullptr) {
				throw std::runtime_error("No se puede eliminar el máximo sin árbol");
			}
			
			else if(n->right == nullptr) {
				return n->left;
			} else {
				n->right = remove_max(n->right);
				return n;
			}
		}

		BSNode<T> *remove(BSNode<T> *n, T e) {
			if(n == nullptr) {
				throw std::runtime_error("No existe el elemento a eliminar");
			}
			
			else if(e < n->elem) {
				n->left = remove(n->left, e);
			} else if(e > n->elem) {
				n->right = remove(n->right, e);
			} 
			
			else {
				
				if(n->left != nullptr && n->right != nullptr) {
					n->elem = max(n->left);
					n->left = remove_max(n->left);
				} 
				
				else {
					
					n = (n->left != nullptr) ? n->left : n->right;
				}
			}
			
			return n;
		}

		
		void delete_cascada(BSNode<T> *n) {
			if(n != nullptr) {
				delete_cascada(n->left);
				delete_cascada(n->right);
				delete n;
			}
		}




	public:
		
		BSTree() {
			root = nullptr;
			nelem = 0;
		}

		
		int size() const {
			return nelem;
		}

		
		T search(T e) const {
			return search(root, e)->elem;
		}


		T operator[](T e) const {
			return search(e);	
		}

		
		void insert(T e) {
			root = insert(root, e);
			nelem++;
		}

		
		friend std::ostream &operator<<(std::ostream &out, const BSTree<T> &bst) {
			bst.print_inorder(out, bst.root);
			return out;
		}

		
		void remove(T e) {
			root = remove(root, e);
			nelem--;
		}
		
		~BSTree() {
			delete_cascada(root);
		}
		
};
	
#endif	
