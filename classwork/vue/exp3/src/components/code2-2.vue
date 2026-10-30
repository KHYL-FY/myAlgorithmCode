<script setup>
import { ref, reactive } from 'vue';
const msg1 = ref("洛阳牡丹甲天下!")
setTimeout(() => {
    msg1.value = "花开时节动京城!"
}, 3000)

const obj = reactive({
    name: "张朵",
    age: 20, 
    sex: "女"
})
setTimeout(() => {
    obj.name = "李四"
    obj.age = 40
    obj.sex = "男"
}, 5000)
</script>

<template>
    <h1>软工2541王艺杰</h1>
    <h1>{{ msg1 }}</h1>
    <h1>姓名:　{{ obj.name }} <br>
        年龄: {{ obj.age }} <br>
        性别: {{ obj.sex }} 
    </h1>
</template>

<style scoped>
h1{
    background-color: pink;
}
</style>