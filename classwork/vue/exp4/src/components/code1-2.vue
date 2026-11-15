<script setup>
import { ref } from 'vue';

const n1 = ref(0)
const n2 = ref(0)
const opt = ref('*')
const result = ref(0)
const cal = () => {
    switch (opt.value) {
        case "+":
            result.value = n1.value + n2.value;
            break;
        case "-":
            result.value = n1.value - n2.value;
            break;
        case "*":
            result.value = n1.value * n2.value;
            break;
        case "/":
            result.value = (n1.value / n2.value).toFixed(2);
            break;
    }
}

</script>

<template>
<h1>软工2541班王艺杰</h1>
    <input type="text" v-model.number="n1">
    <select v-model="opt">
        <option value="+">+</option>
        <option value="-">-</option>
        <option value="*">*</option>
        <option value="/">/</option>
    </select>
    <input type="text" v-model.number="n2">
    <input type="button" value="=" @click="cal">
    <input type="text" disabled :value="result">
</template>

<style scoped>
input[type=text]{
    width: 180px;
}
input,
select {
    font-size: 30px;
}

input[type=button] {
    margin-left: 10px;
    margin-right: 10px;
}
</style>