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
Radix ordena los numero por comprobacion binaria, ordnea por las posiciones de los bits,  
compara cada bit con 1 mediante la operacion &, asi se asegura ordenar todos los bits segun el movimiento desado  
al ordenar todas las posiciones de los bits en binario reducimos el numero de comprobaciones y nos aseguramos que se van a ir stackeando en la pila b por orden descendente decimal, lo que al pushearlo de vuelta nos lo ordena ascendentemente  
el operador x>>n desplaza n bits de x a la derecha asi comprobamos el bit q queremos revisar y el operador & realiza la operazion & de las puertas logicas  

  
ejemlo con 6 4 2 3 0 1  
compramos con PRIMER bit  

6 -> 110 -> (110 >> 0) & 1 = 0 -> pb  
4 -> 100 -> (100 >> 0) & 1 = 0 -> pb  
2 -> 010 -> (010 >> 0) & 1 = 0 -> pb  
3 -> 011 -> (011 >> 0) & 1 = 1 -> ra  
0 -> 000 -> (000 >> 0) & 1 = 0 -> pb  
1 -> 001 -> (001 >> 0) & 1 = 1 -> ra  

stack a-> 1 3;  
stack b-> 6 4 2 0  
lo devolvemos stack a-> 0 2 4 6 1 3  


Comparamos con el SEGUNDO bit  
ejmplo >> (011 >> 1) = 101 entonces 1 & 1 = 1  
3 -> 011 -> (011 >> 1) & 1 = 1 -> ra  
1 -> 001 -> (001 >> 1) & 1 = 0 -> pb  
6 -> 110 -> (110 >> 1) & 1 = 1 -> ra  
4 -> 100 -> (100 >> 1) & 1 = 0 -> pb  
2 -> 010 -> (010 >> 1) & 1 = 1 -> ra   
0 -> 000 -> (000 >> 1) & 1 = 0 -> pb  


stack a-> 2 6 3;  
stack b-> 1 4 0  
lo devolvemos stack a-> 0 2 4 6 1 3  
  
comparamos con TERCER bit  
3 -> 011 -> (011 >> 2) & 1 = 0 -> pb  
6 -> 110 -> (110 >> 2) & 1 = 1 -> ra    
2 -> 010 -> (010 >> 2) & 1 = 0 -> pb  
1 -> 001 -> (001 >> 2) & 1 = 0 -> pb  
4 -> 100 -> (100 >> 2) & 1 = 1 -> ra  
0 -> 000 -> (000 >> 2) & 1 = 0 -> pb  
  
stack a-> 4 6;  
stack b -> 3 2 1 0  
al pasarlo  
stack a-> 0 1 2 3 4 6  

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
            if (((*stack_a)->index >> i) & 1)  //si la posicion en la que se encuentra el numero al comparar con >> con el numero de bit es 1 quiere q es el bit menos significatico de esa comparacion
                ra(stack_a); 
            else
                pb(stack_b, stack_a, nab); //lo llevamos a la pila b cuando i y el index tiene un bit significtavo al comprar
            j++;
        }
        i++;
        while (*stack_b)
            pa(stack_a, stack_b, nab); //lo devolvemos a la pila original para ver su nueva relacion con respecto al nuevo valor de i
    }
}
```
