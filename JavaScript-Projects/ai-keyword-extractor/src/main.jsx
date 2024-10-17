import React from 'react'
import ReactDOM from 'react-dom/client'

import './index.css'
import {ChakraProvider} from '@chakra-ui/react'
import Header from './components/Header'
ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <ChakraProvider>
     <Header/>
    </ChakraProvider>
  </React.StrictMode>,
)
