/* Natives

native Iter_Add(Iterator:Name, value);
native Iter_Remove(Iterator:Name, value)
native Iter_Clear(Iterator:Name);
native Iter_Count(Iterator:Name);
native Iter_Contains(Iterator:Name, value);
*/

#define Iterator:%1[%2] 		Iter%1_list[%2], Iter%1_sort[%2], Iter%1_count

#define Iter_Add(%1,%2) 		EditIter_func(%2, Iter%1_list, Iter%1_sort, Iter%1_count, sizeof(Iter%1_list), 1)
#define Iter_Remove(%1,%2) 		EditIter_func(%2, Iter%1_list, Iter%1_sort, Iter%1_count, sizeof(Iter%1_list), 0)
#define Iter_Clear(%1) 			IterClear_func(Iter%1_list, Iter%1_list, Iter%1_count, sizeof(Iter%1_list))
#define Iter_Count(%1)      	(Iter%1_count)
#define Iter_Contains(%1,%2)    (Iter%1_list[%2])
#define Iter_Random(%1)         (Iter%1_sort[random(Iter%1_count)])
#define foreach(%1,%2) 			for(new %2 = Iter%1_sort[0], %2_count; %2_count < Iter%1_count; %2 = Iter%1_sort[++%2_count])

	
stock EditIter_func(idx, list[], sort[], &iter_count, const size, const value)
{
	new count;
	list[idx] = value;
	
	for(new i = 0; i < size; i++)
	{
	    if(list[i]) sort[count] = i, count ++;
	}
	
	iter_count = count;
	return 1;
}

stock IterClear_func(list[], sort[], &iter_count, const size)
{
	for(new i = 0; i < size; i++)
	{
	    list[i] = 0;
	    sort[i] = 0;
	}
	
	iter_count = 0;
	return 1;
}