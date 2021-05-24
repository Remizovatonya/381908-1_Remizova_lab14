#pragma once

template <class TTK, class TTV> class TNode;
template <class TTK, class TTV> class TMap;

template <class TK, class TV>
class TMapIter
{
protected:
	int index;
	TMap<TK, TV>& c;
public:
	TMapIter(TMap<TK, TV>& map);
	TMapIter(TMapIter<TK, TV> const& iterator);
	TMapIter<TK, TV>& GoNext();
	bool IsGoNext();
	TK GetKey();
	TV GetVal();
	TNode<TK, TV> GetNode();
};

template<class TK, class TV>
inline TMapIter<TK, TV>::TMapIter(TMap<TK, TV>& map) : c(map)
{
	index = 0;
}

template<class TK, class TV>
inline TMapIter<TK, TV>::TMapIter(TMapIter<TK, TV> const& iterator) : c(iterator.c)
{
	c = iterator.c;
	index = iterator.index;
}

template<class TK, class TV>
inline TMapIter<TK, TV>& TMapIter<TK, TV>::GoNext()
{
	if (index < c.count)
		index++;
	return *this;
}

template<class TK, class TV>
inline bool TMapIter<TK, TV>::IsGoNext()
{
	return index < c.count;
}

template<class TK, class TV>
inline TK TMapIter<TK, TV>::GetKey()
{
	if (index < c.count)
		return c.mas[index].GetKey();
	return TK();
}

template<class TK, class TV>
inline TV TMapIter<TK, TV>::GetVal()
{
	if (index < c.count)
		return c.mas[index].GetVal();
	return TV();
}

template<class TK, class TV>
inline TNode<TK, TV> TMapIter<TK, TV>::GetNode()
{
	if (index < c.count)
		return c.mas[index];
	return TNode<TK, TV>();
}