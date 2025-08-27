# 42 Push Swap

Este proyecto implementa el algoritmo de ordenación "push_swap" utilizando estructuras de datos tipo pila (stacks). El objetivo es ordenar una lista de números enteros utilizando un conjunto limitado de operaciones, optimizando el número de movimientos.

## Visualizador

Puedes generar números aleatorios y visualizar tus movimientos en:  
https://push-swap-visualizer.vercel.app/  
Desarrollado por [oyhoyhk](https://github.com/oyhoyhk)

---

## Operaciones principales

### SWAP

**Descripción:**  
Intercambia los dos primeros elementos de la pila.

**Implementación:**
```c
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

---

### ROTATE

**Descripción:**  
Desplaza todos los elementos de la pila una posición hacia arriba; el primer elemento pasa a ser el último.

**Implementación:**
```c
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

---

### REVERSE ROTATE

**Descripción:**  
Desplaza todos los elementos de la pila una posición hacia abajo; el último elemento pasa a ser el primero.

**Implementación:**
```c
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

---

### PUSH

**Descripción:**  
Mueve el primer elemento de una pila (origen) al principio de otra pila (destino).

**Implementación:**
```c
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

---

## Algoritmo de ordenación: Radix Sort

El algoritmo Radix Sort ordena los números utilizando la representación binaria de sus índices. Se compara cada bit mediante desplazamientos y operaciones lógicas, asegurando que los números se distribuyan en las pilas de acuerdo al valor de cada bit en cada iteración. Esto permite ordenar eficientemente grandes cantidades de números con un número mínimo de movimientos.

---

### Ejemplo detallado de Radix Sort

Supón que tenemos los números: `6 4 2 3 0 1`.  
A continuación, se muestra cómo se procesa cada número en cada iteración, mostrando su representación binaria, la operación de bit, el resultado y el movimiento correspondiente:

#### 1ª iteración (bit 0)
| Número | Binario | Operación              | Resultado | Movimiento |
|--------|---------|------------------------|-----------|------------|
|   6    | 110     | (110 >> 0) & 1 = 0     |     0     |    pb      |
|   4    | 100     | (100 >> 0) & 1 = 0     |     0     |    pb      |
|   2    | 010     | (010 >> 0) & 1 = 0     |     0     |    pb      |
|   3    | 011     | (011 >> 0) & 1 = 1     |     1     |    ra      |
|   0    | 000     | (000 >> 0) & 1 = 0     |     0     |    pb      |
|   1    | 001     | (001 >> 0) & 1 = 1     |     1     |    ra      |

- **stack a:** 1 3  
- **stack b:** 6 4 2 0  
- Al devolver los elementos de `b` a `a` → **stack a:** 0 2 4 6 1 3

#### 2ª iteración (bit 1)
| Número | Binario | Operación              | Resultado | Movimiento |
|--------|---------|------------------------|-----------|------------|
|   3    | 011     | (011 >> 1) & 1 = 1     |     1     |    ra      |
|   1    | 001     | (001 >> 1) & 1 = 0     |     0     |    pb      |
|   6    | 110     | (110 >> 1) & 1 = 1     |     1     |    ra      |
|   4    | 100     | (100 >> 1) & 1 = 0     |     0     |    pb      |
|   2    | 010     | (010 >> 1) & 1 = 1     |     1     |    ra      |
|   0    | 000     | (000 >> 1) & 1 = 0     |     0     |    pb      |

- **stack a:** 2 6 3  
- **stack b:** 1 4 0  
- Al devolver los elementos de `b` a `a` → **stack a:** 0 4 1 2 6 3

#### 3ª iteración (bit 2)
| Número | Binario | Operación              | Resultado | Movimiento |
|--------|---------|------------------------|-----------|------------|
|   3    | 011     | (011 >> 2) & 1 = 0     |     0     |    pb      |
|   6    | 110     | (110 >> 2) & 1 = 1     |     1     |    ra      |
|   2    | 010     | (010 >> 2) & 1 = 0     |     0     |    pb      |
|   1    | 001     | (001 >> 2) & 1 = 0     |     0     |    pb      |
|   4    | 100     | (100 >> 2) & 1 = 1     |     1     |    ra      |
|   0    | 000     | (000 >> 2) & 1 = 0     |     0     |    pb      |

- **stack a:** 4 6  
- **stack b:** 3 2 1 0  
- Al devolver los elementos de `b` a `a` → **stack a:** 0 1 2 3 4 6

---

**En cada iteración, el algoritmo revisa cada bit de los índices de los números y mueve los elementos entre las pilas `a` y `b` según el valor del bit. Así se logra el orden deseado con una cantidad mínima de movimientos.**

---

### Implementación de la función de ordenación

```c
void	sort_stack(t_stacks **stack_a, t_stacks **stack_b, t_data *nab)
{
	int	i;
	int	j;
	int	stack_size;

	i = 0;
	stack_size = ft_lstsize(*stack_a);
	while (is_sorted(stack_a) == -1)
	{
		j = 0;
		while (*stack_a && j < stack_size && is_sorted(stack_a) == -1)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a, nab);
			j++;
		}
		i++;
		while (*stack_b)
			pa(stack_a, stack_b, nab);
	}
}
```

---

## Notas

- Todos los códigos deben cumplir con la [norma de estilo 42 (Norminette)](https://github.com/42School/norminette).
- Si tienes dudas sobre el funcionamiento de alguna función, revisa los comentarios en el código o consulta la documentación oficial de la escuela 42.

---
