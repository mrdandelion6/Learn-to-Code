import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  const [count, setCount] = useState(0)

  return (

    //////////////////////////////////////////////////////////////
    <>
      <div>
        <a href="https://vitejs.dev" target="_blank">
          <img src={viteLogo} className="logo" alt="Vite logo" />
        </a>
        <a href="https://react.dev" target="_blank">
          <img src={reactLogo} className="logo react" alt="React logo" />
        </a>
      </div>
      <h1>Vite + React</h1>
      <div className="card">
        <button onClick={() => setCount((count) => count + 1)}>
          count is {count}
        </button>
        <p>
          Edit <code>src/App.tsx</code> and save to test HMR
        </p>
      </div>
      <p className="read-the-docs">
        Click on the Vite and React logos to learn more 
      </p>
      {/* ////////////////////////////////////////////////////////////// */}

    <section className="notes">
      
      <h2>Notes</h2>
      <p>The setState function that comes from the useState hook in React has two forms. It can either accept a direct value or a function.</p>
      <p>Function: When you pass a function to setState, it's called a functional update. The function you pass will receive the previous state value as its argument and should return the new state value. This is useful when the new state depends on the previous state.</p>
      
    
    </section>
    </>
  )
}

export default App
