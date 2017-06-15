
///===> DAL IMPLEMENTATION
//---------------------------------------------------------------------------

/// Returns the index the the key is found, or -1
template < typename Key, typename Data, typename KeyComparator >
int DAL< Key, Data, KeyComparator >::_search(const Key& k_) const
{
	for (auto i(0); i < m_length; i++) {
		if (m_data[i].m_id == k_)
			return i;
	}
	return -1;
}

/// Removes a element by Key
template < typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::remove(const Key& k_, Data& d_)
{
	if( m_length == 0 ) return false;

	int idx = _search( k_ );
	if( idx == -1 ) return false;

	d_ = m_data[idx].m_info;
	m_data[idx] = m_data[m_length-1];
	m_length--;

	return true;
}

/// Searchs for a element in array
template < typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::search(const Key& k_, Data& d_) const
{
	int idx = _search(k_);
	if (idx == -1) return false;

	d_ = m_data[idx].m_info;
	return true;
}

/// Inserts a new element in the array
template < typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::insert(const Key& k_, const Data& d_)
{
	if (_search(k_) >= 0)
		return false;

	m_data[m_length++] = { k_, d_};
	return true;
}

/// Returns the smallest key from the DAL.
template < typename Key, typename Data, typename KeyComparator >
Key DAL< Key, Data, KeyComparator >::min( void ) const
{
	auto *fast( &m_data[0] ), *slow( &m_data[0] );

	for( ; fast != &m_data[m_length]; ++fast )
	{
		if( fast->m_id < slow->m_id )
		{
			slow = fast;
		}
	}

	return slow->m_id;
}

/// Returns the greatest key from the DAL.
template < typename Key, typename Data, typename KeyComparator >
Key DAL< Key, Data, KeyComparator >::max( void ) const
{
	auto *fast( &m_data[0] ), *slow( &m_data[0] );

	for( ; fast != &m_data[m_length]; ++fast )
	{
		if( fast->m_id > slow->m_id )
		{
			slow = fast;
		}
	}

	return slow->m_id;
}

/// Finds the sucessor of the informed key.
template < typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::sucessor( const Key & k_, Key & suc_ ) const
{
	auto max_key = max();

	if( max_key == k_ )
	{
		suc_ = -1;
		return false;
	}
	
	auto suc(k_);
	for( auto i(0); i != m_length; ++i )
	{
		if( m_data[i].m_id > k_ )
		{
			if( suc <= k_ or m_data[i].m_id < suc )
			{
				suc = m_data[i].m_id;
			}
		}
	}
	
	suc_ = suc;

	return true;
}

/// Finds the predecessor of the informed key.
template < typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::predecessor(const Key & k_, Key & pred_) const
{
	auto min_key = min();

	if( min_key == k_ )
	{
		pred_ = -1;
		return false;
	}
	
	auto pred(k_);
	for( auto i(0); i != m_length; ++i )
	{
		if( m_data[i].m_id < k_ )
		{
			if( pred >= k_ or m_data[i].m_id > pred )
			{
				pred = m_data[i].m_id;
			}
		}
	}
	
	pred_ = pred;

	return true;
}


///===> DSAL IMPLEMENTATION
//---------------------------------------------------------------------------

/// Returns the index the the key is found, or -1
template < typename Key, typename Data, typename KeyComparator >
int DSAL< Key, Data, KeyComparator >::_search(const Key& k_) const
{
	for (auto i(0); i < m_length; i++) {
		if (m_data[i].m_id == k_)
			return i;
	}
	return -1;
}
/// Removes a element by Key
template < typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::remove(const Key& k_, Data& d_)
{
	if( m_length == 0 ) return false;

	int idx = _search( k_ );
	if( idx == -1 ) return false;

	d_ = m_data[idx].m_info;
	m_data[idx] = m_data[m_length-1];
	m_length--;

	//std::sort( m_data, m_data + m_length, []( const Node &node1, const Node &node2  )
	//										{ return node1.m_id < node2.m_id; } );

	std::sort( m_data, m_data + m_length, []( const Node &node1, const Node &node2  )
										{ return KeyComparator()( node1.m_id, node2.m_id ); } );

	return true;
}

/// Searchs for a element in array
template < typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::search(const Key& k_, Data& d_) const
{
	int idx = _search(k_);
	if (idx == -1) return false;

	d_ = m_data[idx].m_info;
	return true;
}

/// Inserts a new element in the array
template < typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::insert(const Key& k_, const Data& d_)
{
	if (_search(k_) >= 0)
		return false;

	m_data[m_length++] = { k_, d_};

	//std::sort( m_data, m_data + m_length, []( const Node &node1, const Node &node2  )
	//									{ return node1.m_id < node2.m_id; } );

	std::sort( m_data, m_data + m_length, []( const Node &node1, const Node &node2  )
										{ return KeyComparator()( node1.m_id, node2.m_id ); } );

	return true;
}

/// Returns the smallest key from the DSAL.
template < typename Key, typename Data, typename KeyComparator >
Key DSAL< Key, Data, KeyComparator >::min( void ) const
{
	return m_data[0].m_id;
}

/// Returns the greatest key from the DSAL.
template < typename Key, typename Data, typename KeyComparator >
Key DSAL< Key, Data, KeyComparator >::max( void ) const
{
	
	return m_data[m_length-1].m_id;
}

/// Finds the sucessor of the informed key.
template < typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::sucessor( const Key & k_, Key & suc_ ) const
{
	auto index = _search( k_ );

	if( index < 0 or index == m_length-1 ){
		suc_ = -1;
		return false;
	}

	suc_ = m_data[index+1].m_id;

	return true;
}

/// Finds the predecessor of the informed key.
template < typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::predecessor(const Key & k_, Key & pred_) const
{
	auto index = _search( k_ );

	if( index <= 0 ){
		pred_ = -1;
		return false;
	}

	pred_ = m_data[index-1].m_id;

	return true;
}
