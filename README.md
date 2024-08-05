**SWAP**
*CREO UN PUNTERO AUXILIAR Y OTRO Q ES EL INMEDATIAMENTE POSTERIOR NODO
UTILIZO UN INT PARA ALMACENAR LOS VALORES DEL PRIMERO 
Y SIMPLEMENTE LOS INTERCAMBIO*
```c
  //SWAP 2 POS 1->2 2->1
void	swap(t_stacks **stack)
{
	t_stacks	*point;
	t_stacks	*next;
	int			aux;
	int			i_aux;

	point = *stack;
	next = point->next;
	if (point == NULL && next == NULL)
		exit(EXIT_FAILURE);
	aux = point->data;
	i_aux = point->index;
	point->index = next->index;
	point->data = next->data;
	next->data = aux;
	next->index = i_aux;
}
```

**ROTATE**
*IGUALO UN PUNTERO A LA LISTA Y OTRO AL ULTIMO ELEMENTO DE LA LISTA
MUEVO TODO UNA POSICION QUITANDO LA PRIMERA POSICION
EN P_START SOLO ESTA EL PRIMER NODO Y EL NEXT ES NULL 
ASI QUE LO PONEMOS AL FINAL DEL ULTIMO NODO*

```c
//FIRST TO LAST
void	ra(t_stacks **a)
{
	t_stacks	*p_start;
	t_stacks	*p_end;

	p_start = *a;
	p_end = last_element(p_start);
	*a = p_start->next;
	p_start->next = NULL;
	p_end->next = p_start;
	ft_printf("ra\n");
}
```

**RROTATE**
*CREO DOS PUNTEROS, UNO DE CABEZA Y OTRO DE FINAL 
Y RECORRO LA LISTA HASTA QUE LLEGO AL FINAL. 
EL ANTERIOR LO HAGO EL ÚLTIMO Y COMO EN EL PUNTERO 
DEL FINAL TENGO EL ÚLTIMO ELEMENTO, IGUALO EL NEXT AL STACK SIN EL ÚLTIMO 
(LO HICIMOS NULL AL RECORRER). LA LISTA LA IGUALAMOS A ESE PUNTERO.*

```c
//   LAST TO FIRST
void	rotate(t_stacks **stack)
{
	t_stacks	*p_start;
	t_stacks	*p_end;

	p_start = *stack;
	p_end = last_element(p_start);
	while (p_start != NULL)
	{
		if (p_start->next->next == NULL)
		{
			p_start->next = NULL;
			break ;
		}
		p_start = p_start->next;
	}
	p_end->next = *stack;
	*stack = p_end;
}
```

**PUSH**
*USO UN PUNTERO AUXILIAR Q SE IGUALA AL DE ORIGEN
	SI EL DESTINO ESTA VACIO LO IGUALO Y LO IGUALO AL STACK DE DESTINO
	SI NO AÑADO JUSTO DESPUES DEL PRIMERO EN EL AUXILIAR TODO EL DESTINO*

 ```c
//SACA EL PRIMERO Y LO METE EN EL OTRO STACK
void	push(t_stacks **dest, t_stacks **og)
{
	t_stacks	*aux;
	t_stacks	*point_dest;
	t_stacks	*point_og;

	if (ft_lstsize(*og) == 0)
		return ;
	point_dest = *dest;
	point_og = *og;
	aux = point_og;
	point_og = point_og->next;
	*og = point_og;
	if (point_dest == NULL)
	{
		point_dest = aux;
		point_dest->next = NULL;
		*dest = point_dest;
	}
	else
	{
		aux->next = point_dest;
		*dest = aux;
	}
	return ;
}
```

**SORT FUNCION Y RADIX**
