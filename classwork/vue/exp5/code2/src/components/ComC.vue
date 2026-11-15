<template>
    <h1>我是组件ComC</h1>
    <div class="box">
        <p>我是组件ComC里面的段落</P>
        <MyComA></MyComA> <!--  使用全局注册组件MyComA  -->
    </div>
</template>

<script setup>

</script>

<!-- 当style拥有属性scoped时，它的CSS样式就只能作用于当前组件，
     通过该属性可以使得组件之间的样式不互相污染 -->
<style scoped>
h1{
    width: 300px;
    color: blue;
    background-color: beige;
}
div.box {
    width: 500px;
    height: 300px;
    background-color: bisque;
}
p {
    color: red;
}
</style>
