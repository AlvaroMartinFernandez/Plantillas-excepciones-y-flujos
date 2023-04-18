#if !defined(_EMPRESA_CPP)
#define _EMPRESA_CPP

template<class T>
CEmpresa<T>::CEmpresa(const CEmpresa& a) : m_nElem(0), m_pElem(NULL) {
	*this = a;
}

template<class T>
CEmpresa<T>& CEmpresa<T>::operator=(const CEmpresa& a) {
  if (this == &a) return *this;
  CEmpresa<T>::~CEmpresa();
  m_nElem = a.m_nElem;
  if (m_pElem = new T[m_nElem])
  {
    cout << "Insuficiente memoria\n";
    return *this;
  }
  for(int i=0; i < m_nElem; i++)
    m_pElem[i] = a.m_pElem[i];
	
  return *this;
}

template<class T>
CEmpresa<T>::~CEmpresa() {
  if (m_pElem == NULL) return;
	delete [] m_pElem;
}

template<class T>
void CEmpresa<T>::AgregarElemento(const T &elem) {
	T* nuevo = new T[m_nElem + 1];
	for(int i=0; i < m_nElem; i++)
		nuevo[i] = m_pElem[i];
	nuevo[m_nElem] = elem;
	m_nElem++;
	delete [] m_pElem;
	m_pElem = nuevo;
}

template<class T>
T& CEmpresa<T>::GetElemento(int nElem) const {
	return m_pElem[nElem];
}

template<class T>
T& CEmpresa<T>::operator[](int nElem) const {
	return m_pElem[nElem];
}

#endif