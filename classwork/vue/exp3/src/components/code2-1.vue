<script setup>
import { ref } from 'vue'

const msg = ref("庭前芍药妖无格，池上芙蕖净少情.")
const num1 = 10, num2 = 20, flag = 1
const arr = [11, 22, 33, 44]
const obj = {
    name: "张三",
    age: 20,
     sex: '男',
}

setTimeout(() => {
    msg.value = "唯有牡丹真国色,花开时节动京城."
}, 2000)
</script>

<template>
    <h1>软工2541王艺杰</h1>
    <h2>{{ msg }}</h2>
    <h2>{{ num1 + num2 }}</h2>
    <h2>{{ num1>num2 }}</h2>
    <h2>{{ flag? 'YES':'NO' }}</h2>
    <h2>{{ arr[3] }}</h2>
    <h2>{{ obj.name }}</h2>
</template>

<style scoped>
h1{
    color: red;
    background-color: aqua;
}

div{
    width: 300px;
    height: 100px;
    background-color: bisque;
    font-size: 30px;
}
</style>