#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include <string>
#include <algorithm>

template < typename Key, typename Data, typename KeyComparator >
class DAL
{
	private:
		struct Node {
			Key m_id;
			Data m_info;
		};

		static const int SIZE = 50;
		int m_length;
		int m_capacity;
		Node * m_data;
		
		int _search(const Key &) const;

	public:
		//=== Special functions
		DAL(int sz_ = SIZE)
			: m_capacity(sz_),
			  m_data(new Node[sz_])
		{ 
			m_length = 0;
	   	}
		virtual ~DAL() { delete [] m_data; }

		bool remove(const Key &, Data &); // Removes from the DAL
		bool search(const Key &, Data &) const;
		bool insert(const Key &, const Data &);
		Key min() const;
		Key max() const;
		bool sucessor(const Key &, Key &) const;
		bool predecessor(const Key &, Key &) const;

		inline friend std::ostream &operator<< (std::ostream& os_, const DAL& dic) {
			os_ << "[ ";
			for ( auto i(0); i < dic.m_length; i++) {
				os_ << "{ id: " << dic.m_data[i].m_id << ", info: " << dic.m_data[i].m_info << "}, "; 
			}
			os_ << "]";
			return os_;
		}
};

template < typename Key, typename Data, typename KeyComparator >
class DSAL
{
	private:
		struct Node {
			Key m_id;
			Data m_info;
		};

		static const int SIZE = 50;
		int m_length;
		int m_capacity;
		Node * m_data;
		
		int _search(const Key &) const;

	public:
		//=== Special functions
		DSAL(int sz_ = SIZE)
			: m_capacity(sz_),
			  m_data(new Node[sz_])
		{ 
			m_length = 0;
	   	}
		virtual ~DSAL() { delete [] m_data; }

		bool remove(const Key &, Data &); // Removes from the DSAL
		bool search(const Key &, Data &) const;
		bool insert(const Key &, const Data &);
		Key min() const;
		Key max() const;
		bool sucessor(const Key &, Key &) const;
		bool predecessor(const Key &, Key &) const;

		inline friend std::ostream &operator<< (std::ostream& os_, const DSAL& dic) {
			os_ << "[ ";
			for ( auto i(0); i < dic.m_length; i++) {
				os_ << "{ id: " << dic.m_data[i].m_id << ", info: " << dic.m_data[i].m_info << "}, "; 
			}
			os_ << "]";
			return os_;
		}
};


#include "dictionary.inl"

#endif
