import { createApp } from 'vue'
// import './style.css'
import App from './App.vue'

import MyComA from './components/ComA.vue'
import MyComB from './components/ComB.vue'
import MyComC from './components/ComC.vue'
const app = createApp(App)

app.component('MyComA', MyComA)
app.component('MyComB', MyComB)

app.mount('#app')
