import {Box, Container} from '@chakra-ui/react'
import Header from './components/Header'

function App() {

  return (
    <Box bg='blue.600' color ='white' height='100vh' paddingTop={130} >
      <Container maxW='3xl' centerContent >
        <h2>hello world</h2>
         <Header />
      </Container>
    </Box>
  )
}

export default App
