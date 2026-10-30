<script setup>
import { ref } from 'vue'
const msg = ref("古之立大事者，不惟有超世之才，亦必有坚忍不拔之志。")
let intervalId = null
const dong = () => {
    if(intervalId != null) return
    intervalId = setInterval(() => {
        let start = msg.value.substring(0, 1)
        let end = msg.value.substring(1)
        msg.value = end + start
    }, 1000)
}
const stop = () => {
    clearInterval(intervalId)
    intervalId = null
}
</script>

<template>
    <h1>软工2541班王艺杰</h1>
    <button type="button" @click="dong">跑起来</button>
    <button type="button" @click="stop">停止</button>
    <h1>{{ msg }}</h1>
</template>

<style scoped>
</style>
