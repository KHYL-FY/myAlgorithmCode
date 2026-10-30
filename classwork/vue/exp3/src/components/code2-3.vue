<script setup>
const message = '<strong>软件学院<strong>'
const link = '<a href="http://www.haust.edu.cn">河南科技大学</a>'
</script>

<template>
    <h1>软工2541班王艺杰</h1>
    <p>河南科技大学{{ message }}</p>
    <p v-text="message"></p>
    <p v-html="message"></p>
    <p v-html="link"></p>
    <p v-text="link"></p>
    <p v-html="message + '------------'"></p>
</template>

<style scoped>
h1{text-align: center;}
p{
    font-size: 25px;
}
</style>