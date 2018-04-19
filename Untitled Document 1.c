void RotateLeft(struct node *a)
{
	struct node *b;

	b = a->right;
	a->right= b->left;

	if(b->left !=gp)
        b->left->parent = a;

	b->parent = a->parent;

	if(a->parent == gp )
		root = b;
	else if( a == a->parent->left )
		a->parent->left = b;
	else
		a->parent->right = b;
    b->left = a;
	a->parent = b;
}
