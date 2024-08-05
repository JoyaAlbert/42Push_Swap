para coger numeros aleatorios https://push-swap-visualizer.vercel.app/ desarrollado por https://github.com/oyhoyhk

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
Radix ordena los numero por orden de las cifras es decir si tienes
->Original:  170, 45, 75, 90, 802, 24, 2, 66
primero ordena los que tiene 3 cifras quedando -> 170, 90, 802, 2, 24, 45, 75, 66 
por que solo revisamos la ultima cifra
ahora la siguiente cifra, tenemos->802, 2, 24, 45, 66, 170, 75, 90 y asi hasta hacer todas
esto lo vamos a hacer con comporbacion de bits, un contador nos va indiciar q bit es siendo el bit 0 las unidades y asi veamos en el codigo
```c
void sort_stack(t_stacks **stack_a, t_stacks **stack_b, t_data *nab)
{
    int i; //nuestro contador de bits
    int j; //nustro contador de numeros del stack
    int stack_size;

    i = 0;
    stack_size = ft_lstsize(*stack_a); // tamaño de numeros en el stack
    while (is_sorted(stack_a) == -1) //mintras que no este ordenado
    {
        j = 0;
        while (*stack_a && j < stack_size && is_sorted(stack_a) == -1)  //mientras que no sea NULL ni nos hayamos pasado del numero de elementos en el stack ni este ordenado
        {
            if (((*stack_a)->index >> i) & 1)  //si la posicion en la que se encuentra el numero al comparar con >> con el numero de bit es 1 quiere decir que es mas grande que las unidades lo rotamos a la ultima posicion 
                ra(stack_a); 
            else
                pb(stack_b, stack_a, nab); //lo llevamos a la pila b ciando i y el index son iguales
            j++;
        }
        i++;
        while (*stack_b)
            pa(stack_a, stack_b, nab); //lo devolvemos a la pila original
    }
}
``

